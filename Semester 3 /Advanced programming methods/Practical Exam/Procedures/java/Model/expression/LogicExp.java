package Model.expression;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.type.BoolType;
import Model.type.Type;
import Model.value.BoolValue;
import Model.value.Value;

public class LogicExp implements Exp {
    Exp e1;
    Exp e2;
    int op;  //1- a&&b 2- a||b

    public LogicExp( int op,Exp e1, Exp e2) {
        this.e1 = e1;
        this.e2 = e2;
        this.op = op;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl, MyIHeap heap) throws ExprException, ADTException, MyException {
        Value v1, v2;
        v1 = e1.eval(tbl,heap);
        if (v1.getType().equals(new BoolType())) {
            v2 = e2.eval(tbl,heap);
            if (v2.getType().equals(new BoolType())) {
                BoolValue i1 = (BoolValue) v1;
                BoolValue i2 = (BoolValue) v2;
                boolean n1, n2;
                n1 = i1.getVal();
                n2 = i2.getVal();
                if(op==1)
                    return new BoolValue(n1&&n2);
                else
                    if(op==2)
                        return new BoolValue(n1||n2);
            }
            else{
                throw new ExprException("Second operand isn't boolean!");
            }
        }
        else{
            throw new ExprException("First operand isn't boolean");
        }
        return new BoolValue(false);
    }

    public String toString(){
        return this.e1+ " "+ this.op + " " + this.e2.toString();
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type type1,type2;
        type1=e1.typeCheck(typeEnv);
        type2=e2.typeCheck(typeEnv);
        if(type1.equals(new BoolType())){
            if(type2.equals(new BoolType())){
                return new BoolType();
            }
            else throw new MyException(String.format("Second exp %s not of bool type",e2.toString()));
        }
        else throw new MyException(String.format("First exp %s not of bool type",e1.toString()));
    }
}