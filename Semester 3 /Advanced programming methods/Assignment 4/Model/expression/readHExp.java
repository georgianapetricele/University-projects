package Model.expression;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.type.RefType;
import Model.value.RefValue;
import Model.value.Value;

public class readHExp implements Exp{

    Exp exp;

    public readHExp(Exp expression){
        this.exp=expression;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl, MyIHeap heap) throws ExprException, ADTException {
        Value val = exp.eval(tbl,heap);
        if(!(val instanceof RefValue))
            throw new ExprException(String.format("Expression %s not of Ref Type",exp.toString()));
        RefValue castVal=(RefValue) val;
        int address=castVal.getAddr();
        if(!heap.containsKey(address))
            throw new ADTException(String.format("Address %d not in heap keys",address));
        return heap.get(address);
    }

    @Override
    public String toString() {
        return String.format("ReadHeap(%s)", exp);
    }
}
