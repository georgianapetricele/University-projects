package Controller;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.value.RefValue;
import Model.value.Value;
import Repository.IRepository;

import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {
    IRepository repo;
    boolean displayFlag;

    ExecutorService executor;

    public Controller(IRepository repo)
    {
        this.repo=repo;
        this.displayFlag=false;
    }

    public IRepository getRepo(){
        return repo;
    }
    public List<PrgState> getPrgStatesList(){
        return this.repo.getPrgList();
    }

    public void setPrgStatesList(List<PrgState> newList){
        this.repo.setPrgList(newList);
    }


    public void setDisplayFlag(boolean value){
        this.displayFlag=value;
    }


    public List<Integer> getAddrFromSymTable(Collection<Value> symTableValues){
        return symTableValues.stream()
                .filter(v-> v instanceof RefValue)
                .map(v-> {RefValue v1 = (RefValue)v; return v1.getAddr();})
                .collect(Collectors.toList());
    }

    public List<Integer> getAddrFromHeap(Collection<Value> heapValues) {
        return heapValues.stream()
                .filter(v -> v instanceof RefValue)
                .map(v -> {RefValue v1 = (RefValue) v; return v1.getAddr();})
                .collect(Collectors.toList());
    }

    public Map<Integer, Value> safeGarbageCollector(List<Integer> symTableAddr,List<Integer> heapAddr, Map<Integer,Value>
            heap){
        return heap.entrySet().stream()
                .filter(e->(symTableAddr.contains(e.getKey()) || heapAddr.contains(e.getKey())))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));}

    public Map<Integer, Value> unsafeGarbageCollector(List<Integer> symTableAddr,Map<Integer,Value>
            heap){
        return heap.entrySet().stream()
                .filter(e->symTableAddr.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));}

    //one step for each existing PrgState (namely each thread)
    public void oneStepForAllPrg(List<PrgState> prgList) throws InterruptedException {
        //before the execution, print the PrgState List into the log file
        prgList.forEach(prg -> {
            try {
                repo.logPrgStateExec(prg);
            } catch (MyException | IOException e) {
                System.out.println(e.getMessage());
            }
        });
        //RUN concurrently one step for each of the existing PrgStates
        //prepare the list of callables
        //se face onestep pe fiecare prgstate deodata

        List<Callable<PrgState>> callList = prgList.stream()
                .map((PrgState p) -> (Callable<PrgState>)(() -> {return p.oneStep();}))
                .collect(Collectors.toList());
        System.out.println(callList.stream().collect(Collectors.toList()).toString());
        //start the execution of the callables
        //it returns the list of new created PrgStates (namely threads)
        // because of invoke all we need a list of future(that have the one step), then get the result from one step=>list prgstate
        List<PrgState> newPrgList = executor.invokeAll(callList). stream()
                . map(future -> {
                    try {
                        return future.get();
                    }
                    catch(ExecutionException | InterruptedException e)
                    {
                        System.out.println(e.getMessage());
                    }
                    return null;
                })
                .filter(p -> p!=null)
                .collect(Collectors.toList());
        //add the new created threads to the list of existing threads
        prgList.addAll(newPrgList);
        //after the execution, print the PrgState List into the log file
        prgList.forEach(prg -> {
            try {
                repo.logPrgStateExec(prg);
            } catch (MyException | IOException e) {
                System.out.println(e.getMessage());
            }
        });
        //Save the current programs in the repository
        repo.setPrgList(prgList);

    }

    public void oneStep() throws InterruptedException {
        executor = Executors.newFixedThreadPool(2);
        List<PrgState> prgList=removeCompletedPrg(repo.getPrgList());
        oneStepForAllPrg(prgList);
        //call garbage collector
        repo.getPrgList().stream().forEach(program -> program.getHeap().setContent((HashMap<Integer,Value>)safeGarbageCollector(
                getAddrFromSymTable(program.getSymTable().getContent().values()),
                getAddrFromHeap(program.getHeap().getContent().values()),
                program.getHeap().getContent())));

        prgList.forEach(e -> {
            try {
                repo.logPrgStateExec(e);
            } catch (IOException | MyException e1) {
                System.out.println();
            }
        });

        executor.shutdownNow();
    }

    public void allSteps() throws MyException, ADTException, ExprException, StmtException, IOException, InterruptedException,RuntimeException {

        executor = Executors.newFixedThreadPool(2);
        //remove the completed programs
        List<PrgState> prgList=removeCompletedPrg(repo.getPrgList());
        while(prgList.size() > 0){

            repo.getPrgList().stream().forEach(program -> program.getHeap().setContent((HashMap<Integer,Value>)safeGarbageCollector(
                    getAddrFromSymTable(program.getSymTable().getContent().values()),
                    getAddrFromHeap(program.getHeap().getContent().values()),
                    program.getHeap().getContent())));

            oneStepForAllPrg(prgList);
            //remove the completed programs
            prgList=removeCompletedPrg(repo.getPrgList());
        }
        executor.shutdownNow();
        //the repository still contains at least one Completed Prg
        // and its List<PrgState> is not empty. Note that oneStepForAllPrg calls the method

        // update the repository state
        repo.setPrgList(prgList);

    }

    public  List<PrgState> removeCompletedPrg(List<PrgState> inPrgList){
        return inPrgList.stream()
                .filter(p -> p.isNotCompleted())
                .collect(Collectors.toList());
    }




}
