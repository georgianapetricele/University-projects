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
        MyIStack<IStmt> stk= state.getExeStk();
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
        return null;
    }

    public String toString() {
        return "while("+exp.toString()+")"+"{"+stmt+"}";
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type typexp = exp.typeCheck(typeEnv);
        if(typexp.equals(new BoolType())){
            stmt.typeCheck(typeEnv.clone()); //creates a clone to ensure not modifying the original environment
            return typeEnv;
        }
        else throw new MyException("Condition exp isn't boolean");
    }
}


