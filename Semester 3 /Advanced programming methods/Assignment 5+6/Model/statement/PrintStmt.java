package Model.statement;
import Model.PrgState;
import Model.expression.*;
import Model.type.Type;
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
    public MyIDictionary<String, Type> typecheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        exp.typecheck(typeEnv); //check if the expression is well defined not throwing exception
        return typeEnv; //type environment unchanged because print don't introduce any new var
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
        return null;
    }

}
