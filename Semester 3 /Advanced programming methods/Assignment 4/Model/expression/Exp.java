package Model.expression;
import Model.value.*;
import Exceptions.*;
import Model.adt.*;

public interface Exp {
    public Value eval(MyIDictionary<String,Value> tbl,MyIHeap heap) throws ExprException, ADTException;
    public String toString();
}