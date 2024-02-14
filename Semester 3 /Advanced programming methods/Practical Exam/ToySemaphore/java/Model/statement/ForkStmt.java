package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.*;
import Model.type.Type;
import Model.value.StringValue;
import Model.value.Value;

import java.io.BufferedReader;

public class ForkStmt implements IStmt{

    IStmt stmt;

    public ForkStmt(IStmt stmt){
        this.stmt=stmt;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
            MyIStack<IStmt> stk = new MyStack<>();
            stk.push(stmt);
            MyIDictionary<String,Value> symTable=state.getSymTable().clone();
            MyIDictionary<StringValue, BufferedReader> fileTable=state.getFileTable();
            MyIList<Value> outConsole= state.getOut();
            MyIHeap heap=state.getHeap();

        return new PrgState(stk,symTable,outConsole,fileTable,heap,state.getSemaphoreTable());
    }

    @Override
    public String toString(){
        return "fork("+this.stmt.toString()+")";
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        stmt.typeCheck(typeEnv.clone());
        return typeEnv;
    }
}
