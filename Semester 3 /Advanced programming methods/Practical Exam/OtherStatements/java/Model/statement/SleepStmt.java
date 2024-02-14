package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIStack;
import Model.type.Type;

public class SleepStmt implements IStmt{

    int number;
    public SleepStmt(int number){
        this.number=number;
    }
    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        if(number>0)
        {
            MyIStack<IStmt> exeStack = state.getExeStk();
            exeStack.push(new SleepStmt(number - 1));
            state.setExeStack(exeStack);
        }
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        return typeEnv;
    }

    public String toString(){
        return "sleep("+number+")";
    }
}
