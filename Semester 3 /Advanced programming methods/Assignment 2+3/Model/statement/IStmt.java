package Model.statement;

import Model.PrgState;
import Exceptions.*;

public interface IStmt{
    PrgState execute(PrgState state) throws MyException,StmtException,ExprException,ADTException;

    String toString();
    //which is the execution method for a statement.


}