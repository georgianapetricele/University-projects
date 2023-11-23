package Model.expression;
import Model.value.*;
import Exceptions.*;
import Model.adt.*;

public interface Exp {
    public Value eval(MyIDictionary<String,Value> tbl) throws ExprException;
    public String toString();
}