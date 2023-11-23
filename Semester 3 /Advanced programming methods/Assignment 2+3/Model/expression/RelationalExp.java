package Model.expression;

import Exceptions.ExprException;
import Model.type.IntType;
import Model.adt.MyIDictionary;
import Model.value.BoolValue;
import Model.value.IntValue;
import Model.value.Value;

import java.util.Objects;

public class RelationalExp implements Exp{
    Exp exp1;
    Exp exp2;
    String operator;

    public RelationalExp(String operator, Exp expression1, Exp expression2) {
        this.exp1 = expression1;
        this.exp2 = expression2;
        this.operator = operator;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symTable) throws ExprException {
        Value value1, value2;
        value1 = this.exp1.eval(symTable);
        if (value1.getType().equals(new IntType())) {
            value2 = this.exp2.eval(symTable);
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
                throw new ExprException("Second operand is not an integer.");
        } else
            throw new ExprException("First operand in not an integer.");
        return null;
    }

    @Override
    public String toString() {
        return this.exp1.toString() + " " + this.operator + " " + this.exp2.toString();
    }
}