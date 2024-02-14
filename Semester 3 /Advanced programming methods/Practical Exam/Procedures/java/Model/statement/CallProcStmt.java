package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyDictionary;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.adt.MyIProcTable;
import Model.expression.Exp;
import Model.type.Type;
import Model.value.Value;

import java.util.List;

public class CallProcStmt implements IStmt{

    private final String procedureName;
    private final List<Exp> expressions;

    public CallProcStmt(String procedureName, List<Exp> expressions) {
        this.procedureName = procedureName;
        this.expressions = expressions;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        MyIDictionary<String, Value> symTable = state.getTopSymTable();
        MyIHeap heap = state.getHeap();
        MyIProcTable procTable = state.getProcTable();
        //check ProcTable and extract the list of the variables v1,..vn and
        //the body statement for the procedure fname.
        if (procTable.isDefined(procedureName)) {
            List<String> variables = procTable.lookup(procedureName).getKey();
            IStmt statement = procTable.lookup(procedureName).getValue();
            //create a new SymTable
            MyIDictionary<String, Value> newSymTable = new MyDictionary<>();
            //that contains the mappings of the formal
            //variables vi to the value of the current arguments of every procedure
            //(namely vi->eval(expi))
            for(String var: variables) {
                int ind = variables.indexOf(var);
                newSymTable.update(var, expressions.get(ind).eval(symTable, heap));
            }
            //push new SymTable on the stack of SymTables
            //push the statement return on the ExeStack (statement return is
            //defined below)
            //push the body of the procedure fname on the ExeStack
            state.getSymTable().push(newSymTable);
            state.getExeStk().push(new ReturnStmt());
            state.getExeStk().push(statement);
        } else {
            throw new MyException("Procedure not defined!");
        }
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        return typeEnv;
    }

    @Override
    public String toString(){
        return String.format("Call %s%s", procedureName, expressions.toString());
    }
}
