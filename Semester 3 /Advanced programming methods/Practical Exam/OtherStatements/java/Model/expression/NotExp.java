package Model.expression;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.type.Type;
import Model.value.BoolValue;
import Model.value.Value;

public class NotExp implements Exp{
    private final Exp expression;

    public NotExp(Exp expression) {
        this.expression = expression;
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        return expression.typeCheck(typeEnv);
    }

    @Override
    public Value eval(MyIDictionary<String, Value> table, MyIHeap heap) throws MyException, ExprException, ADTException {
        BoolValue value = (BoolValue) expression.eval(table, heap);
        if (!value.getVal())
            return new BoolValue(true);
        else
            return new BoolValue(false);
    }


    @Override
    public String toString() {
        return String.format("!(%s)", expression);
    }
}