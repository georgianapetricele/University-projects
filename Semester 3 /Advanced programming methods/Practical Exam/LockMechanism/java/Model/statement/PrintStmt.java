package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.adt.MyIList;
import Model.adt.MyIStack;
import Model.expression.Exp;
import Model.type.Type;
import Model.value.Value;

public class PrintStmt implements IStmt {
    Exp exp;

    public PrintStmt(Exp exp){

        this.exp=exp;
    }

    @Override
    public String toString(){
        return "print(" +exp.toString()+")";
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        exp.typeCheck(typeEnv); //check if the expression is well defined not throwing exception
        return typeEnv; //type environment unchanged because print don't introduce any new var
    }

    @Override
    public PrgState execute(PrgState state) throws StmtException, ExprException, ADTException, MyException {
        MyIStack<IStmt> stk = state.getExeStk();
        MyIList<Value> outConsole= state.getOut();
        MyIHeap heap=state.getHeap();
        Value val= exp.eval(state.getSymTable(),heap);
        outConsole.add(val);  //add to the out console the value from the evaluated exp
        state.setExeStack(stk);
        state.setOut(outConsole);
        return null;
    }

}
