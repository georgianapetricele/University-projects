package Model.expression;
import Model.type.Type;
import Model.value.*;
import Exceptions.*;
import Model.adt.*;

public interface Exp {
    public Value eval(MyIDictionary<String,Value> tbl,MyIHeap heap) throws ExprException, ADTException;
    public String toString();

    public Type typecheck(MyIDictionary<String,Type> typeEnv) throws MyException;
}