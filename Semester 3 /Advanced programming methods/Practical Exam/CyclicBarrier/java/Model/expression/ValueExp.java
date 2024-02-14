package Model.expression;

import Exceptions.ExprException;
import Exceptions.MyException;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.type.Type;
import Model.value.Value;

public class ValueExp implements Exp{
    Value e;

    public ValueExp(Value e){

        this.e=e;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl, MyIHeap heap) throws ExprException {
        return e;
    }

    @Override
    public String toString(){
        return this.e.toString();
    }

    public Type typeCheck(MyIDictionary<String,Type> typeEnv) throws MyException {
        return e.getType();
    }

}