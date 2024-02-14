package Model.statement;

import Exceptions.MyException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyILock;
import Model.type.IntType;
import Model.type.Type;
import Model.value.IntValue;
import Model.value.Value;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class UnLockStmt implements IStmt{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public UnLockStmt(String var) {
        this.var = var;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        lock.lock();
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyILock lockTable = state.getLockTable();
        if (symTable.isDefined(var)) {
            if (symTable.lookup(var).getType().equals(new IntType())) {
                IntValue fi = (IntValue) symTable.lookup(var);
                int foundIndex = fi.getVal();
                if (lockTable.containsKey(foundIndex)) {
                    if (lockTable.get(foundIndex) == state.getId())
                        lockTable.update(foundIndex, -1);
                } else {
                    throw new MyException("Index not in the lock table!");
                }
            } else {
                throw new MyException("Var is not of int type!");
            }
        } else {
            throw new MyException("Variable is not defined!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        if (typeEnv.lookup(var).equals(new IntType()))
            return typeEnv;
        else
            throw new MyException("Var is not of type int!");
    }

    @Override
    public String toString() {
        return String.format("unlock(%s)", var);
    }
}
