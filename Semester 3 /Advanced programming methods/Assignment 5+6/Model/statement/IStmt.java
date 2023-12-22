package Model.statement;

import Model.PrgState;
import Exceptions.*;
import Model.adt.MyIDictionary;
import Model.type.Type;

public interface IStmt{
    PrgState execute(PrgState state) throws MyException,StmtException,ExprException,ADTException;

    String toString();
    //which is the execution method for a statement.

    MyIDictionary<String, Type> typecheck(MyIDictionary<String,Type> typeEnv) throws MyException, ADTException;

}