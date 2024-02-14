package Model.statement;

import Exceptions.ADTException;
import Exceptions.MyException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIStack;
import Model.type.Type;

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
        MyIStack<IStmt> stk=state.getExeStk();
        stk.push(snd);
        stk.push(first);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        //MyIDictionary<String,Type> typEnv1 = first.typecheck(typeEnv);
        //MyIDictionary<String,Type> typEnv2 = snd.typecheck(typEnv1);
        //return typEnv2;
        return snd.typeCheck(first.typeCheck(typeEnv));
    }

    //private IStmt deepCopy(IStmt prg){
        //return new CompStmt(first.deepCopy(),snd.deepCopy());
    //}
}
