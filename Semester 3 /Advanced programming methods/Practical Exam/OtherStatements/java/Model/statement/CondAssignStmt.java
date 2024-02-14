package Model.statement;

import Exceptions.MyException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIStack;
import Model.expression.VarExp;
import Model.type.BoolType;
import Model.type.Type;
import Model.expression.Exp;

public class CondAssignStmt implements IStmt{

    String var;
    Exp exp1;
    Exp exp2;
    Exp exp3;

    public CondAssignStmt(String var,Exp exp1,Exp exp2,Exp exp3) {
        this.var=var;
        this.exp1=exp1;
        this.exp2=exp2;
        this.exp3=exp3;
    }
    @Override
    public PrgState execute(PrgState state){
        MyIStack<IStmt> exeStack = state.getExeStk();
        // we create a new if statement which has as condition exp1 and assigns to v exp2 if exp1 is true, and exp3 otherwise
        IStmt converted = new IfStmt(exp1, new AssignStmt(var, exp2), new AssignStmt(var, exp3));
        // and we push the statement on the stack
        exeStack.push(converted);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        // we evaluate the variable v and the expressions exp1, exp2, exp3
        Type variableType = new VarExp(var).typeCheck(typeEnv);
        Type type1 = exp1.typeCheck(typeEnv);
        Type type2 = exp2.typeCheck(typeEnv);
        Type type3 = exp3.typeCheck(typeEnv);
        // exp1 must be of type bool and exp2 and exp3 must have the same type as var
        if (type1.equals(new BoolType()) && type2.equals(variableType) && type3.equals(variableType))
            return typeEnv;
        else
            throw new MyException("The conditional assignment is invalid!");
    }

    @Override
    public String toString() {
        return " "+var+"="+exp1.toString()+"?"+exp2.toString()+":"+exp3.toString()+" ";
    }
}
