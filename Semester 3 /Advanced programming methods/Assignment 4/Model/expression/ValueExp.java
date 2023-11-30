package Model.expression;
import Exceptions.*;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.value.*;

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
}