package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyILatchTable;
import Model.expression.ValueExp;
import Model.type.IntType;
import Model.type.Type;
import Model.value.IntValue;
import Model.value.Value;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
public class CountDownStmt implements IStmt{

    private String var;
    private static Lock lock = new ReentrantLock();

    public CountDownStmt(String var) {
        this.var = var;
    }
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        lock.lock();
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyILatchTable latchTable = state.getLatchTable();
        //var is mapped with an index into the latchTable
        // we check if var was defined in the sym table, if not we throw an error message
        if (symTable.isDefined(var)) {
            // we look up for the index to which var is mapped and if we don't find it in the latch table we throw an error message
            IntValue index = (IntValue) symTable.lookup(var);
            int foundIndex = index.getVal();
            if (latchTable.containsKey(foundIndex)) {
                // if the found index is greater than 0, we decrease LatchTable[foundIndex] with 1,
                if (latchTable.get(foundIndex) > 0) {
                    latchTable.update(foundIndex, latchTable.get(foundIndex) - 1);
                }
                // else write into Out table the current prgState id
                state.getExeStk().push(new PrintStmt(new ValueExp(new IntValue(state.getId()))));
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
        return "CountDown(" + var + ")";
    }
}
