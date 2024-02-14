package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.adt.MyIStack;
import Model.expression.Exp;
import Model.expression.ValueExp;
import Model.type.BoolType;
import Model.type.Type;
import Model.value.BoolValue;
import Model.value.IntValue;
import Model.value.Value;

public class WaitStmt implements IStmt{
    private int number;

    public WaitStmt(int number) {
        this.number = number;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        if (number != 0) {
            MyIStack<IStmt> stack = state.getExeStk();
            stack.push(new CompStmt(
                    new PrintStmt(new ValueExp(new IntValue(number))),
                    new WaitStmt(number - 1)));
            state.setExeStack(stack);
        }
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        return typeEnv;
    }

    @Override
    public String toString() {
        return "Wait(" + number + ")";
    }
}
