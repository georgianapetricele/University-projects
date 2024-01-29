package Model.expression;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.type.RefType;
import Model.type.Type;
import Model.value.RefValue;
import Model.value.Value;

public class readHExp implements Exp{

    Exp exp;

    public readHExp(Exp expression){
        this.exp=expression;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl, MyIHeap heap) throws ExprException, ADTException, MyException {
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


    public Type typeCheck(MyIDictionary<String,Type> typeEnv) throws MyException {
        Type typ=exp.typeCheck(typeEnv);
        if (typ instanceof RefType) {
            RefType reft =(RefType) typ;
            return reft.getInner(); //get the type of the value stored in the reference
        } else
            throw new MyException("the rH argument is not a Ref Type");
    }
}
