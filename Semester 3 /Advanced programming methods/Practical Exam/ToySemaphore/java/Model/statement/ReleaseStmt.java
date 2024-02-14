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

public class ReleaseStmt implements IStmt{

    private final String var;
    private static final Lock lock = new ReentrantLock();

    public ReleaseStmt(String var) {
        this.var = var;
    }
    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        lock.lock();
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyISemaphore semaphoreTable = state.getSemaphoreTable();
        //foundIndex=lookup(SymTable,var). If var is not in SymTable or has not
        //int type then print an error message and terminate the execution
        if (symTable.isDefined(var)) {
            if (symTable.lookup(var).getType().equals(new IntType())) {
                IntValue fi = (IntValue) symTable.lookup(var);
                int foundIndex = fi.getVal();
                //if foundIndex is an index in the SemaphoreTable
                if (semaphoreTable.containsKey(foundIndex)) {
                    //retrieve the entry for that foundIndex
                    //SemaphoreTable[foundIndex]== (N1,List1,N2)
                    Tuple<Integer, List<Integer>, Integer> foundSemaphore = semaphoreTable.get(foundIndex);
                    //if(the id of the current PrgState is in List1) then
                    //- remove the identifier of the current PrgState from List1
                    if (foundSemaphore.getSecond().contains(state.getId())) {
                        foundSemaphore.getSecond().remove((Integer) state.getId());
                    }
                    semaphoreTable.update(foundIndex, new Tuple<>(foundSemaphore.getFirst(), foundSemaphore.getSecond(), foundSemaphore.getThird()));
                } else {
                    throw new MyException("Index not found in the semaphore table!");
                }
            } else {
                throw new MyException("Index must be of int type!");
            }
        } else {
            throw new MyException("Index not found in the symbol table!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        return typeEnv;
    }

    @Override
    public String toString() {
        return "Release("+ var+")";
    }
}
