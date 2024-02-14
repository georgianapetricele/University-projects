package Model.statement;

import Exceptions.ADTException;
import Exceptions.MyException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.expression.Exp;
import Model.type.BoolType;
import Model.type.Type;

public class DoWhileStmt implements IStmt{
    private final IStmt statement;
    private final Exp expression;

    public DoWhileStmt(Exp expression, IStmt statement) {
        this.statement = statement;
        this.expression = expression;
    }
    @Override
    public PrgState execute(PrgState state) throws MyException {
        IStmt converted = new CompStmt(statement, new WhileStmt(expression, statement));
        state.getExeStk().push(converted);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type typeExpression = expression.typeCheck(typeEnv);
        if (typeExpression.equals(new BoolType())) {
            statement.typeCheck(typeEnv.clone());
            return typeEnv;
        } else
            throw new MyException("Condition in the do while statement must be bool!");
    }

    @Override
    public String toString() {
        return String.format("Do {%s} while (%s)", statement, expression);
    }
}