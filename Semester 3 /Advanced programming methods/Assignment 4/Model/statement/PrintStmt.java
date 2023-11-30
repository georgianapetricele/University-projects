package Model.statement;
import Model.PrgState;
import Model.expression.*;
import Model.value.Value;
import Model.adt.*;
import Exceptions.*;

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
    public PrgState execute(PrgState state) throws StmtException, ExprException, ADTException {
        MyIStack<IStmt> stk = state.getStk();
        MyIList<Value> outConsole= state.getOut();
        MyIHeap heap=state.getHeap();
        Value val= exp.eval(state.getSymTable(),heap);
        outConsole.add(val);  //add to the out console the value from the evaluated exp
        state.setExeStack(stk);
        state.setOut(outConsole);
        return state;
    }

}
