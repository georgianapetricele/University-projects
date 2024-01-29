package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.adt.MyIStack;
import Model.expression.Exp;
import Model.type.BoolType;
import Model.type.Type;
import Model.value.BoolValue;
import Model.value.Value;

public class IfStmt implements IStmt {
    Exp exp;
    IStmt thenS;
    IStmt elseS;

    public IfStmt(Exp e, IStmt t, IStmt el) {
     exp=e;
     thenS=t;
     elseS=el;
 }
    public String toString(){
        return "(IF("+ exp.toString()+") THEN(" +thenS.toString() +")ELSE("+elseS.toString()+"))";}

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type typexp=exp.typeCheck(typeEnv);
        if (typexp.equals(new BoolType())) {
            thenS.typeCheck(typeEnv.clone()); //to make sure that any changes in one branch don't impact the other or the original environment
            elseS.typeCheck(typeEnv.clone());
            return typeEnv;
        }
        else
            throw new MyException("The condition of IF has not the type bool");
    }

    public PrgState execute(PrgState state) throws StmtException, ExprException, ADTException, MyException {
        MyIStack<IStmt> stk = state.getExeStk();
        MyIHeap heap=state.getHeap();
        Value cond = exp.eval(state.getSymTable(),heap); //evaluate the condition

        if (cond instanceof BoolValue) {
            IStmt statement;
            BoolValue c = (BoolValue) cond;
            if (c.getVal()) {
                statement = thenS;
            } else {
                statement = elseS;
            }

            stk.push(statement);
            state.setExeStack(stk);
            return null;
        } else
            throw new StmtException("Condition isn't boolean!");
    }
}