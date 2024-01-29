package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.adt.MyILatchTable;
import Model.expression.Exp;
import Model.type.IntType;
import Model.type.Type;
import Model.value.IntValue;
import Model.value.Value;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewLatchStmt implements IStmt {
    private final String var;
    private final Exp expression;
    private static Lock lock = new ReentrantLock();

    public NewLatchStmt(String var, Exp expression) {
        this.var = var;
        this.expression = expression;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException, ExprException, ADTException {
        lock.lock();
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIHeap heap = state.getHeap();
        MyILatchTable latchTable = state.getLatchTable();
        // we evaluate the expression in order to get its value
        IntValue nb = (IntValue) expression.eval(symTable, heap);
        int number = nb.getVal();
        //LatchTable2 = LatchTable1 synchronizedUnion {newfreelocation ->num1}
        // we get the free address and put the result of the evaluation number in it
        int freeAddress = latchTable.getFreeAddress();
        latchTable.put(freeAddress, number);
        // if var is defined in symtable we update its value
        // throw an error message otherwise
        if (symTable.isDefined(var)) {
            symTable.update(var, new IntValue(freeAddress));
        }
        else {
            throw new MyException("Var is not defined!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        // both variable and expression must have type int
        if (typeEnv.lookup(var).equals(new IntType())) {
            if (expression.typeCheck(typeEnv).equals(new IntType())) {
                return typeEnv;
            }
            else {
                throw new MyException("Expression must have type int!");
            }
        }
        else {
            throw new MyException("Var must be of type int!");
        }
    }

    @Override
    public String toString() {
        return "NewLatch(" + var + ", " + expression + ")";
    }
}
