package Model.statement;


import Exceptions.MyException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIStack;
import Model.expression.Exp;
import Model.expression.RelationalExp;
import Model.expression.VarExp;
import Model.type.IntType;
import Model.type.Type;

public class ForStmt implements IStmt{
    private final String variable;
    private final Exp expression1;
    private final Exp expression2;
    private final Exp expression3;
    private final IStmt statement;

    public ForStmt(String variable, Exp expression1, Exp expression2, Exp expression3, IStmt statement) {
        this.variable = variable;
        this.expression1 = expression1;
        this.expression2 = expression2;
        this.expression3 = expression3;
        this.statement = statement;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIStack<IStmt> exeStack = state.getExeStk();
        IStmt converted = new CompStmt(new AssignStmt("v", expression1),
                new WhileStmt(new RelationalExp("<", new VarExp("v"), expression2),
                        new CompStmt(statement, new AssignStmt("v", expression3))));
        exeStack.push(converted);
        state.setExeStack(exeStack);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type type1 = expression1.typeCheck(typeEnv);
        Type type2 = expression2.typeCheck(typeEnv);
        Type type3 = expression3.typeCheck(typeEnv);

        if (type1.equals(new IntType()) && type2.equals(new IntType()) && type3.equals(new IntType()))
            return typeEnv;
        else
            throw new MyException("The for statement is invalid!");
    }


    @Override
    public String toString() {
        return String.format("For(%s=%s; %s<%s; %s=%s) {%s}", variable, expression1, variable, expression2, variable, expression3, statement);
    }
}
