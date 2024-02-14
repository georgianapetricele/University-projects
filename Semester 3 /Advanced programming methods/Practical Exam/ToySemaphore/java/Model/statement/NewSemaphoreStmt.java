package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.adt.Tuple;
import Model.expression.Exp;
import Model.type.IntType;
import Model.type.Type;
import Model.value.IntValue;
import Model.value.Value;

import java.util.ArrayList;
import Model.adt.MyISemaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewSemaphoreStmt implements IStmt{

    private final String var;
    private final Exp expression1;
    private final Exp expression2;
    private static final Lock lock = new ReentrantLock();

    public NewSemaphoreStmt(String var, Exp expression1, Exp expression2) {
        this.var = var;
        this.expression1 = expression1;
        this.expression2 = expression2;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        lock.lock();
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIHeap heap = state.getHeap();
        MyISemaphore semaphoreTable = state.getSemaphoreTable();
        //evaluate the expression exp1 and exp2 using SymTable1 and Heap1
        //and let be number1 and number2 the results of this evaluation
        IntValue nr1 = (IntValue) (expression1.eval(symTable, heap));
        IntValue nr2 = (IntValue) (expression2.eval(symTable, heap));
        int number1 = nr1.getVal();
        int number2 = nr2.getVal();
        //SemaphoreTable2 = SemaphoreTable1 synchronizedUnion
        //{newfreelocation ->(number1,empty list,number2)}
        int freeAddress = semaphoreTable.getFreeAddress();
        semaphoreTable.put(freeAddress, new Tuple<>(number1, new ArrayList<>(), number2));
        //if var exists in SymTable1 and has the type int then
        //SymTable2 = update(SymTable1,var, newfreelocation)
        //update var with the value at the free address
        if (symTable.isDefined(var) && symTable.lookup(var).getType().equals(new IntType()))
            symTable.update(var, new IntValue(freeAddress));
        else
            throw new MyException(String.format("%s in not defined in the symbol table!", var));
        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        return typeEnv;
    }

    public String toString(){
        return "NewSemaphore("+ var +","+expression1.toString()+","+expression2.toString()+")";
    }
}
