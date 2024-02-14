package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.type.Type;

public class ReturnStmt implements IStmt{
    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        //pop the top of the stack of SymTable (namely restore the local
        //variables of the caller)
        state.getSymTable().pop();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        return typeEnv;
    }

    @Override
    public String toString(){
        return "Return";
    }
}
