package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.type.Type;

public interface IStmt{
    PrgState execute(PrgState state) throws MyException,StmtException,ExprException,ADTException;

    String toString();
    //which is the execution method for a statement.

    MyIDictionary<String, Type> typeCheck(MyIDictionary<String,Type> typeEnv) throws MyException, ADTException;

}