package Model.expression;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.type.Type;
import Model.value.Value;

public interface Exp {
    public Value eval(MyIDictionary<String, Value> tbl, MyIHeap heap) throws ExprException, ADTException;

    public String toString();

    public Type typecheck(MyIDictionary<String, Type> typeEnv) throws MyException;
}