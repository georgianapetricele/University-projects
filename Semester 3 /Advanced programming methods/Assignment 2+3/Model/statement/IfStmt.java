package Model.statement;
import Model.PrgState;
import Model.expression.Exp;
import Model.type.BoolType;
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
    public PrgState execute(PrgState state) throws StmtException,ExprException {
        MyIStack<IStmt> stk = state.getStk();
        Value cond = exp.eval(state.getSymTable()); //evaluate the condition

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
            return state;
        } else
            throw new StmtException("Condition isn't boolean!");
    }
}