package Model.statement;

import Exceptions.MyException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyISemaphore;
import Model.type.IntType;
import Model.type.Type;
import Model.value.IntValue;
import Model.value.Value;
import javafx.util.Pair;

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
    public PrgState execute(PrgState state) throws MyException {
        lock.lock();
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyISemaphore semaphoreTable = state.getSemaphoreTable();
        /*
        - pop the statement
        - foundIndex=lookup(SymTable,var). If var is not in SymTable or has not
        the type int then print an error message and terminate the execution.
         */
        if (symTable.isDefined(var)) {
            if (symTable.lookup(var).getType().equals(new IntType())){
                IntValue fi = (IntValue) symTable.lookup(var);
                int foundIndex = fi.getVal();
                /*
                if foundIndex is an entry in SemaphoreTable retrieve the entry for that foundIndex, as
                SemaphoreTable[foundIndex]== (N1,List1)
                 */
                if (semaphoreTable.getSemaphoreTable().containsKey(foundIndex)) {
                    Pair<Integer, List<Integer>> foundSemaphore = semaphoreTable.get(foundIndex);
                    //- compute the length of that list List1 as NL=length(List1)
                    int NL = foundSemaphore.getValue().size();
                    int N1 = foundSemaphore.getKey();
                    if (N1 > NL) {
                        /*
                        if (N1>NL) then
                            if(the identifier of the current PrgState is NOT in List1)
                            add the id of the current PrgState to List1
                         */
                        if (!foundSemaphore.getValue().contains(state.getId())) {
                            foundSemaphore.getValue().add(state.getId());
                            semaphoreTable.update(foundIndex, new Pair<>(N1, foundSemaphore.getValue()));
                        }
                    }
                    //else push back acquire(var) on the ExeStack
                    else {
                        state.getExeStk().push(this);
                    }
                } else {
                    throw new MyException("Index not a key in the semaphore table!");
                }
            } else {
                throw new MyException("Index must be of int type!");
            }
        } else {
            throw new MyException("Index not in symbol table!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        if (typeEnv.lookup(var).equals(new IntType())) {
            return typeEnv;
        } else {
            throw new MyException(String.format("%s is not int!", var));
        }
    }

    @Override
    public String toString() {
        return String.format("Acquire(%s)", var);
    }
}
