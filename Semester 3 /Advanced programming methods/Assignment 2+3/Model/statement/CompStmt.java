package Model.statement;
import Model.PrgState;
import Model.expression.Exp;
import Model.value.Value;
import Model.adt.*;
import Exceptions.*;

public class CompStmt implements IStmt {
    IStmt first;
    IStmt snd;

    public CompStmt(IStmt first, IStmt snd){
        this.first=first;
        this.snd=snd;
    }

    @Override
    public String toString() {

        return "("+first.toString() + ";" + snd.toString()+")";
    }
    @Override
    public PrgState execute(PrgState state) throws MyException{
        MyIStack<IStmt> stk=state.getStk();
        stk.push(snd);
        stk.push(first);
        return state;
    }

    //private IStmt deepCopy(IStmt prg){
        //return new CompStmt(first.deepCopy(),snd.deepCopy());
    //}
}
