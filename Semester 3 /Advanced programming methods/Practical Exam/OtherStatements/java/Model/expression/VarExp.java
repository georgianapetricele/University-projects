package Model.expression;

import Exceptions.ExprException;
import Exceptions.MyException;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.type.Type;
import Model.value.Value;

public class VarExp implements Exp{
    String id;

    public VarExp(String id){
        this.id=id;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl, MyIHeap heap) throws ExprException {
        return tbl.lookup(id);
    }

    public String toString(){
        return id;
    }

    public Type typeCheck(MyIDictionary<String,Type> typeEnv) throws MyException{
        return typeEnv.lookup(id);
    }
}