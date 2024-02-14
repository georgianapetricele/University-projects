package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyISemaphore;
import Model.adt.Tuple;
import Model.type.IntType;
import Model.type.Type;
import Model.value.IntValue;
import Model.value.Value;

import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class AcquireStmt implements IStmt{

    private final String var;
    private static final Lock lock = new ReentrantLock();

    public AcquireStmt(String var) {
        this.var = var;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        lock.lock();
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyISemaphore semaphoreTable = state.getSemaphoreTable();
        //var represents the key for an entry into the SemaphoreTable
        if (symTable.isDefined(var)) {
            //If var is not in SymTable or has not
            //the type int then print an error message and terminate the execution.
            if (symTable.lookup(var).getType().equals(new IntType())) {
                // foundIndex=lookup(SymTable,var)
                IntValue fi = (IntValue) symTable.lookup(var);
                int foundIndex = fi.getVal();
                //if foundIndex is an index in the SemaphoreTable
                if (semaphoreTable.containsKey(foundIndex)) {
                    //retrieve the entry for that foundIndex as
                    //SemaphoreTable[foundIndex]== (N1,List1,N2)
                    Tuple<Integer, List<Integer>, Integer> foundSemaphore = semaphoreTable.get(foundIndex);
                    //compute the length of that list List1 as NL=length(List1)
                    int NL = foundSemaphore.getSecond().size();
                    int N1 = foundSemaphore.getFirst();
                    int N2 = foundSemaphore.getThird();
                    //if ((N1-N2)>NL) then
                    if ((N1 - N2) > NL) {
                        //if(the identifier of the current PrgState is NOT in List1)
                        if (!foundSemaphore.getSecond().contains(state.getId())) {
                            //add the id of the current PrgState to List1 and update sem table
                            foundSemaphore.getSecond().add(state.getId());
                            semaphoreTable.update(foundIndex, new Tuple<>(N1, foundSemaphore.getSecond(), N2));
                        }
                    } else {
                        //push back acquire(var) on the ExeStack
                        state.getExeStk().push(this);
                    }
                } else {
                    throw new MyException("Index is not in the semaphore table!");
                }
            } else {
                throw new MyException("Index does not have the int type!");
            }
        } else
            throw new MyException("Index not in the symbol table!");
        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        return typeEnv;
    }

    @Override
    public String toString() {
        return "Acquire("+var+")";
    }
}
