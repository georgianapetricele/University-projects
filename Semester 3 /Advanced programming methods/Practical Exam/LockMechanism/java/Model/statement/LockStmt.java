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

public class LockStmt implements IStmt{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public LockStmt(String var) {
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
                    if (lockTable.get(foundIndex) == -1) {
                        lockTable.update(foundIndex, state.getId());
                        state.setLockTable(lockTable);
                    } else {
                        state.getExeStk().push(this);
                    }
                } else {
                    throw new MyException("Index is not in the lock table!");
                }
            } else {
                throw new MyException("Var is not of type int!");
            }
        } else {
            throw new MyException("Variable not defined!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        if (typeEnv.lookup(var).equals(new IntType())) {
            return typeEnv;
        } else {
            throw new MyException("Var is not of int type!");
        }
    }


    @Override
    public String toString() {
        return String.format("Lock(%s)", var);
    }
}
