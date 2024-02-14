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
import Model.type.Type;
import Model.value.Value;


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
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type typeval = typeEnv.lookup(id);
        Type typexp = exp.typeCheck(typeEnv);
        if (typeval.equals(typexp))  //var.val.type=expression.type
            return typeEnv;
        else
            throw new MyException("Assignment: right hand side and left hand side have different types ");
    }

    public PrgState execute(PrgState state) throws StmtException, ExprException, ADTException, MyException {
        MyIStack<IStmt> stk = state.getExeStk();
        MyIStack<MyIDictionary<String, Value>> symbolTable = state.getSymTable();
        MyIDictionary<String, Value> currentSymTable = symbolTable.top();
        MyIHeap heap=state.getHeap();

        if (currentSymTable.isDefined(id)) {
            Value val = exp.eval(currentSymTable,heap);
            Type typId = (currentSymTable.lookup(id)).getType();
            if (val.getType().equals(typId)) {
                currentSymTable.update(id, val);
            } else {
                throw new StmtException("Declared type of variable" + id + " and type of the assigned expression do not match");
            }
        } else {
            throw new StmtException("The used variable " + id + " was not declared before");
        }
        state.setSymTable(symbolTable);
        return null;
    }
}