package Model.statement;

import Exceptions.ADTException;
import Exceptions.MyException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIStack;
import Model.expression.Exp;
import Model.expression.NotExp;
import Model.type.BoolType;
import Model.type.Type;

public class RepeatUntilStmt implements IStmt{
    private final IStmt statement;
    private final Exp expression;

    public RepeatUntilStmt(IStmt statement, Exp expression) {
        this.statement = statement;
        this.expression = expression;
    }
    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIStack<IStmt> exeStack = state.getExeStk();
        IStmt converted = new CompStmt(statement, new WhileStmt(new NotExp(expression), statement));
        exeStack.push(converted);
        state.setExeStack(exeStack);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type type = expression.typeCheck(typeEnv);
        if (type.equals(new BoolType())) {
            statement.typeCheck(typeEnv.clone());
            return typeEnv;
        } else {
            throw new MyException("Expression in the repeat statement must be of Bool type!");
        }
    }

    @Override
    public String toString() {
        return String.format("Repeat(%s) until (%s)", statement, expression);
    }
}
