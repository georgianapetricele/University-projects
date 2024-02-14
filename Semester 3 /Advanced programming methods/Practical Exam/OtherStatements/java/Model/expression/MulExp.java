package Model.expression;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.type.IntType;
import Model.type.Type;
import Model.value.Value;

public class MulExp implements Exp{
    private Exp exp1;
    private Exp exp2;

    public MulExp(Exp exp1, Exp exp2) {
        this.exp1 = exp1;
        this.exp2 = exp2;
    }

    public Exp getExp1() {
        return exp1;
    }

    public void setExp1(Exp exp1) {
        this.exp1 = exp1;
    }

    public Exp getExp2() {
        return exp2;
    }

    public void setExp2(Exp exp2) {
        this.exp2 = exp2;
    }

    @Override
    public String toString() {
        return "MULExp{" +
                "exp1=" + exp1 +
                ", exp2=" + exp2 +
                '}';
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl, MyIHeap heap) throws MyException, ExprException, ADTException {
        Exp converted = new ArithExp('-', new ArithExp('*', exp1, exp2), new ArithExp('+', exp1, exp2));
        return converted.eval(tbl, heap);
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type type1 = exp1.typeCheck(typeEnv);
        Type type2 = exp2.typeCheck(typeEnv);
        if (type1.equals(new IntType()) && type2.equals(new IntType())) {
            return new IntType();
        }
        else {
            throw new MyException("Expressions in MUL must be of type int!");
        }
    }
}
