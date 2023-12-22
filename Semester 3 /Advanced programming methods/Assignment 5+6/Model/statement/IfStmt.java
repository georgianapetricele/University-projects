package Model.statement;
import Model.PrgState;
import Model.expression.Exp;
import Model.type.BoolType;
import Model.type.Type;
import Model.value.BoolValue;
import Model.value.Value;
import Model.adt.*;
import Exceptions.*;

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
    public MyIDictionary<String, Type> typecheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type typexp=exp.typecheck(typeEnv);
        if (typexp.equals(new BoolType())) {
            thenS.typecheck(typeEnv.clone()); //to make sure that any changes in one branch don't impact the other or the original environment
            elseS.typecheck(typeEnv.clone());
            return typeEnv;
        }
        else
            throw new MyException("The condition of IF has not the type bool");
    }

    public PrgState execute(PrgState state) throws StmtException, ExprException, ADTException {
        MyIStack<IStmt> stk = state.getStk();
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