package Model.expression;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.type.IntType;
import Model.type.Type;
import Model.value.IntValue;
import Model.value.Value;

public class ArithExp implements Exp{
    Exp e1;
    Exp e2;
    int op; //1-plus, 2-minus, 3-star, 4-divide

    public ArithExp(char op,Exp e1,Exp e2){
        this.e1=e1;
        this.e2=e2;
        if(op == '+')
            this.op = 1;
        if(op == '-')
            this.op = 2;
        if(op == '*')
            this.op = 3;
        if(op == '/')
            this.op = 4;
    }

    @Override
    public Value eval(MyIDictionary<String,Value> tbl, MyIHeap heap) throws ExprException, ADTException, MyException {
        Value v1,v2;
        v1= e1.eval(tbl,heap);
        if (v1.getType().equals(new IntType())) {
            v2 = e2.eval(tbl,heap);
            if (v2.getType().equals(new IntType())) {
                IntValue i1 = (IntValue)v1;
                IntValue i2 = (IntValue)v2;
                int n1,n2;
                n1= i1.getVal();
                n2 = i2.getVal();
                if (op==1) return new IntValue(n1+n2);
                if (op ==2) return new IntValue(n1-n2);
                if(op==3) return new IntValue(n1*n2);
                if(op==4)
                    if(n2==0) throw new ExprException("division by zero");
                    else return new IntValue(n1/n2);
            }else
                throw new ExprException("second operand is not an integer");
        }else
            throw new ExprException("first operand is not an integer");
        return null;
    }

    @Override
    public String toString() {
        switch (op) {
            case 1:
                return e1.toString() + "+" + e2.toString();
            case 2:
                return e1.toString() + "-" + e2.toString();
            case 3:
                return e1.toString() + "*" + e2.toString();
            case 4:
                return e1.toString() + '/' + e2.toString();
            default:
                return "";
        }
    }

    public Type typeCheck(MyIDictionary<String,Type> typeEnv) throws MyException{
        Type typ1, typ2;
        typ1=e1.typeCheck(typeEnv);
        typ2=e2.typeCheck(typeEnv);
        if(typ1.equals(new IntType())){
            if(typ2.equals(new IntType())){
                return new IntType();
            } else
                    throw new MyException("second operand is not an integer");
        }else
                throw new MyException("first operand is not an integer");
    }

}