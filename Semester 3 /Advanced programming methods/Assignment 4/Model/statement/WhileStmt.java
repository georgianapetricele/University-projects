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
import Model.value.BoolValue;
import Model.value.Value;

public class WhileStmt implements IStmt{

    Exp exp;
    IStmt stmt;

    public WhileStmt(Exp exp,IStmt stmt){
        this.exp=exp;
        this.stmt=stmt;
    }
    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        MyIDictionary<String, Value> symTbl=state.getSymTable();
        MyIHeap heap =state.getHeap();
        MyIStack<IStmt> stk= state.getStk();
        Value val=exp.eval(symTbl,heap);

        if(val instanceof BoolValue)
        {
            BoolValue boolVal=(BoolValue) val;
            if(boolVal.getVal())
            {
              stk.push(this);
              stk.push(stmt);
            }
        }
        else
            throw new ExprException(String.format("Condition exp %s isn't boolean",val.toString()));
        state.setExeStack(stk);
        return state;
    }

    public String toString() {
        return "while("+exp.toString()+")"+"{"+stmt+"}";
    }
}


