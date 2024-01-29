package Model.statement;

import Exceptions.ADTException;
import Exceptions.MyException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIStack;
import Model.expression.Exp;
import Model.expression.RelationalExp;
import Model.type.Type;

public class SwitchStmt implements IStmt{
    private Exp exp;
    private Exp exp1;
    private IStmt stmt1;
    private Exp exp2;
    private IStmt stmt2;
    private IStmt stmt3;



    public SwitchStmt(Exp exp, Exp exp1, IStmt stmt1, Exp exp2, IStmt stmt2, IStmt stmt3) {
        this.exp = exp;
        this.exp1 = exp1;
        this.stmt1 = stmt1;
        this.exp2 = exp2;
        this.stmt2 = stmt2;
        this.stmt3 = stmt3;
    }

    @Override
    public String toString() {
        return "Switch(" + exp +
                ") (case " + exp1 +
                ": " + stmt1 +
                ") (case " + exp2 +
                ": " + stmt2 +
                ") (default: " + stmt3 +
                ')';
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIStack<IStmt> stack = state.getExeStk();

        //- create the following statement:
        //if(exp==exp1) then stmt1 else (if (exp==exp2) then stmt2 else stmt3)
        IStmt converted = new IfStmt(
                                new RelationalExp("==", exp, exp1), stmt1,
                          new IfStmt(
                                new RelationalExp("==", exp, exp2), stmt2, stmt3));
        //push the new statement on the stack
        stack.push(converted);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type type = exp.typeCheck(typeEnv);
        Type type1 = exp1.typeCheck(typeEnv);
        Type type2 = exp2.typeCheck(typeEnv);
        //exp, exp1 and exp2 have the same type
        if (type.equals(type1) && type.equals(type2)) {
            stmt1.typeCheck(typeEnv.clone());
            stmt2.typeCheck(typeEnv.clone());
            stmt3.typeCheck(typeEnv.clone());
            return typeEnv;
        }
        else {
            throw new MyException("The expression types do not match in the switch statement!");
        }
    }
}
