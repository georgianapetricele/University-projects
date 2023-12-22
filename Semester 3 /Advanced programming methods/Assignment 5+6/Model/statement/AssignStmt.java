package Model.statement;

import Model.PrgState;
import Model.expression.Exp;
import Model.value.Value;
import Model.adt.*;
import Exceptions.*;
import Model.type.*;


public class AssignStmt implements IStmt {
    String id;
    Exp exp;

    public AssignStmt(String id,Exp exp){
        this.id=id;
        this.exp=exp;
    }

    public String toString() {

        return id + "=" + exp.toString();
    }

    @Override
    public MyIDictionary<String, Type> typecheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type typeval = typeEnv.lookup(id);
        Type typexp = exp.typecheck(typeEnv);
        if (typeval.equals(typexp))  //var.val.type=expression.type
            return typeEnv;
        else
            throw new MyException("Assignment: right hand side and left hand side have different types ");
    }

    public PrgState execute(PrgState state) throws StmtException, ExprException, ADTException {
        MyIStack<IStmt> stk = state.getStk();
        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyIHeap heap=state.getHeap();
        if (symTbl.isDefined(id)) {
            Value val = exp.eval(symTbl,heap);
            Type typId = (symTbl.lookup(id)).getType();
            if (val.getType().equals(typId)) {
                symTbl.update(id, val);
            } else {
                throw new StmtException("Declared type of variable" + id + " and type of the assigned expression do not match");
            }
        } else {
            throw new StmtException("The used variable " + id + " was not declared before");
        }
        state.setSymTable(symTbl);
        return null;
    }
}