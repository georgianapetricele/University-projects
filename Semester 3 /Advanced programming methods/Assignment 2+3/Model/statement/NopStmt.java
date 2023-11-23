package Model.statement;

import Exceptions.StmtException;
import Model.PrgState;

public class NopStmt implements IStmt{

    @Override
    public PrgState execute(PrgState state) throws StmtException {
        return state;
    }
}
