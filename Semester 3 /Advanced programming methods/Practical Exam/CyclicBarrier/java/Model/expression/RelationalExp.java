package Model.expression;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.type.BoolType;
import Model.type.IntType;
import Model.type.Type;
import Model.value.BoolValue;
import Model.value.IntValue;
import Model.value.Value;

import java.util.Objects;

public class RelationalExp implements Exp {
    Exp exp1;
    Exp exp2;
    String operator;

    public RelationalExp(String operator, Exp expression1, Exp expression2) {
        this.exp1 = expression1;
        this.exp2 = expression2;
        this.operator = operator;
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type type1, type2;
        type1 = exp1.typeCheck(typeEnv);
        type2 = exp2.typeCheck(typeEnv);
        if (type1.equals(new IntType())) {
            if (type2.equals(new IntType())) {
                return new BoolType();
            } else
                throw new MyException("Second operand is not an integer.");
        } else
            throw new MyException("First operand is not an integer.");

    }

    @Override
    public Value eval(MyIDictionary<String, Value> table, MyIHeap heap) throws ExprException, ADTException, MyException {
        Value value1, value2;
        value1 = this.exp1.eval(table, heap);
        if (value1.getType().equals(new IntType())) {
            value2 = this.exp2.eval(table, heap);
            if (value2.getType().equals(new IntType())) {
                IntValue val1 = (IntValue) value1;
                IntValue val2 = (IntValue) value2;
                int v1, v2;
                v1 = val1.getVal();
                v2 = val2.getVal();
                if (Objects.equals(this.operator, "<"))
                    return new BoolValue(v1 < v2);
                else if (Objects.equals(this.operator, "<="))
                    return new BoolValue(v1 <= v2);
                else if (Objects.equals(this.operator, "=="))
                    return new BoolValue(v1 == v2);
                else if (Objects.equals(this.operator, "!="))
                    return new BoolValue(v1 != v2);
                else if (Objects.equals(this.operator, ">"))
                    return new BoolValue(v1 > v2);
                else if (Objects.equals(this.operator, ">="))
                    return new BoolValue(v1 >= v2);
            } else
                throw new MyException("Second operand is not an integer.");
        } else
            throw new MyException("First operand in not an integer.");
        return null;
    }

    @Override
    public String toString() {
        return this.exp1.toString() + " " + this.operator + " " + this.exp2.toString();
    }
}