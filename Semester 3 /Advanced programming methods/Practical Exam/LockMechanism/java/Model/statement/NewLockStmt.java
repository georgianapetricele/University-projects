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

public class NewLockStmt implements IStmt{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public NewLockStmt (String var) {
        this.var = var;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        lock.lock();
        MyILock lockTable = state.getLockTable();
        MyIDictionary<String, Value> symTable = state.getSymTable();
        int freeAddress = lockTable.getFreeValue();
        lockTable.put(freeAddress, -1);
        if (symTable.isDefined(var) && symTable.lookup(var).getType().equals(new IntType()))
            symTable.update(var, new IntValue(freeAddress));
        else
            throw new MyException("Variable not declared!");
        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        if (typeEnv.lookup(var).equals(new IntType()))
            return typeEnv;
        else
            throw new MyException("Var is not of int type!");
    }

    @Override
    public String toString() {
        return String.format("NewLock(%s)", var);
    }
}
