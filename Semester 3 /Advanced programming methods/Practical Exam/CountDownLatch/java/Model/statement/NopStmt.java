package Model.statement;

import Exceptions.ADTException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.type.Type;

public class NopStmt implements IStmt{

    @Override
    public PrgState execute(PrgState state) throws StmtException {
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        return typeEnv;
    }
}
