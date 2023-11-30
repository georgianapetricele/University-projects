package Model.expression;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.value.*;
import Exceptions.*;

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
}