package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyILatchTable;
import Model.type.IntType;
import Model.type.Type;
import Model.value.IntValue;
import Model.value.Value;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class AwaitStmt implements IStmt{
    private String var;
    private static Lock lock = new ReentrantLock();

    public AwaitStmt(String var) {
        this.var = var;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        lock.lock();
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyILatchTable latchTable = state.getLatchTable();
        //var represents a variable from SymTable which is mapped to an index from LatchTable
        // we check if var is defined in symTable and throw an error message if not
        if (symTable.isDefined(var)) {
            //we look up the value of var in symTable
            // the value is an index in the latch table
            //throw an error if the index isn't in latch table
            IntValue index = (IntValue) symTable.lookup(var);
            int foundIndex = index.getVal();
            if (latchTable.containsKey(foundIndex)) {
                // if LatchTable[foundIndex] != 0 we push await statement on the
                // stack, and we must wait until the counter reach 0
                if (latchTable.get(foundIndex) != 0) {
                    state.getExeStk().push(this);
                }
            }
            else {
                throw new MyException("Index not found in latch table!");
            }
        }
        else {
            throw new MyException("Var is not defined!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        if (typeEnv.lookup(var).equals(new IntType())) {
            return typeEnv;
        }
        else {
            throw new MyException("Var must be of type int!");
        }
    }

    public String toString() {
        return "Await(" + var + ")";
    }
}
