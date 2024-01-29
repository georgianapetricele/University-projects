package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.adt.MyISemaphore;
import Model.expression.Exp;
import Model.type.IntType;
import Model.type.Type;
import Model.value.IntValue;
import Model.value.Value;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class CreateSemaphoreStmt implements IStmt{
    private final String var;
    private final Exp expression;
    private static final Lock lock = new ReentrantLock();

    public CreateSemaphoreStmt(String var, Exp expression) {
        this.var = var;
        this.expression = expression;
    }
    @Override
    public PrgState execute(PrgState state) throws MyException, ExprException, ADTException {
        lock.lock();
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIHeap heap = state.getHeap();
        MyISemaphore semaphoreTable = state.getSemaphoreTable();
        /*
        - evaluate the expression exp1 using SymTable1 and Heap1 and let be
        number1 the result of this evaluation. If number1 is not an integer then print an
        error and stop the execution.
         */
        IntValue nr = (IntValue) (expression.eval(symTable, heap));
        int number = nr.getVal();
        /*
        SemaphoreTable2 = SemaphoreTable1 synchronizedUnion {newfreelocation
        ->(number1,empty list)}
         */
        int freeAddress = semaphoreTable.getFreeAddress();
        semaphoreTable.put(freeAddress, new Pair<>(number, new ArrayList<>()));
        /*
        if var exists in SymTable1 and has the type int then
        SymTable2 = update(SymTable1,var, newfreelocation)
        else print an error and stop the execution.
         */
        if (symTable.isDefined(var) && symTable.lookup(var).getType().equals(new IntType()))
            symTable.update(var, new IntValue(freeAddress));
        else
            throw new MyException(String.format("Error for variable %s: not defined/does not have int type!", var));
        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException{
        if (typeEnv.lookup(var).equals(new IntType())) {
            if (expression.typeCheck(typeEnv).equals(new IntType()))
                return typeEnv;
            else
                throw new MyException("Expression is not of int type!");
        } else {
            throw new MyException(String.format("%s is not of type int!", var));
        }
    }

    @Override
    public String toString() {
        return String.format("CreateSemaphore(%s, %s)", var, expression);
    }
}
