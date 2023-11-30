package Controller;

import Model.PrgState;
import Model.adt.MyIStack;
import Model.statement.IStmt;
import Model.value.RefValue;
import Model.value.Value;
import Repository.IRepository;
import Exceptions.*;

import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

public class Controller {
    IRepository repo;
    boolean displayFlag;

    public Controller(IRepository repo)
    {
        this.repo=repo;
        this.displayFlag=false;
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

//    List<Integer> getAddrFromSymTable(Collection<Value> symTableValues, Map<Integer, Value> heap) {
//        List<Integer> toReturn = new ArrayList<>();
//        symTableValues.stream()
//                        .filter(v -> v instanceof RefValue)
//                        .forEach(v -> {
//                            while (v instanceof RefValue) {
//                                toReturn.add(((RefValue) v).getAddr());
//                                v = heap.get(((RefValue) v).getAddr());
//                            }
//                        });
//
//        return toReturn;
//    }

    public Map<Integer, Value> safeGarbageCollector(List<Integer> symTableAddr,List<Integer> heapAddr, Map<Integer,Value>
            heap){
        return heap.entrySet().stream()
                .filter(e->(symTableAddr.contains(e.getKey()) || heapAddr.contains(e.getKey())))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));}

    public Map<Integer, Value> unsafeGarbageCollector(List<Integer> symTableAddr,List<Integer> heapAddr, Map<Integer,Value>
            heap){
        return heap.entrySet().stream()
                .filter(e->symTableAddr.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));}

    public PrgState oneStep(PrgState state) throws MyException,ADTException,ExprException,StmtException{
        MyIStack<IStmt> stk=state.getStk();
        if(stk.isEmpty())
            throw new MyException("Prgstate stack is empty");
        IStmt crtStmt = stk.pop();
        return crtStmt.execute(state);
    }

    public void allSteps() throws MyException, ADTException, ExprException, StmtException, IOException {
        PrgState prg = repo.getPrgCrt(); // repo is the controller field of type MyRepoInterface
        //here you can display the prg state
        if(displayFlag)
            //System.out.println(prg.toString());
            repo.logPrgStateExec(prg);
        while (!prg.getStk().isEmpty()){

            oneStep(prg);
            //here you can display the prg state
            prg.getHeap().setContent((HashMap<Integer, Value>) unsafeGarbageCollector(
                    getAddrFromSymTable(prg.getSymTable().getContent().values()),
                    getAddrFromHeap(prg.getHeap().getContent().values()),
                    prg.getHeap().getContent()));

            if(displayFlag)
                //System.out.println(prg.toString());
                repo.logPrgStateExec(prg);
        }}


}
