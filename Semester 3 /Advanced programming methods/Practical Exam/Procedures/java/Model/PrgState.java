package Model;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.adt.*;
import Model.statement.IStmt;
import Model.value.StringValue;
import Model.value.Value;

import java.io.BufferedReader;


public class PrgState{
    MyIStack<IStmt> exeStack;
    MyIStack<MyIDictionary<String, Value>> symTable;
    MyIDictionary<StringValue,BufferedReader> fileTable;
    MyIHeap heapTable;
    MyIList<Value> out;
    MyIProcTable procTable;
    private int id;
    private static int lastId=0;
    IStmt originalProgram; //optional field, but good to have

    public PrgState(MyIStack<IStmt> stk,MyIStack<MyIDictionary<String,Value>> symtbl, MyIList<Value> ot, MyIDictionary<StringValue, BufferedReader> fileTable, MyIHeap heap,MyIProcTable procTable,IStmt prg){
        exeStack=stk;
        symTable=symtbl;
        this.fileTable=fileTable;
        this.heapTable=heap;
        out = ot;
        this.procTable=procTable;
        originalProgram=prg;//recreate the entire original prg
        stk.push(prg);
        id=setId();
    }

    public PrgState(MyIStack<IStmt> stk,MyIStack<MyIDictionary<String,Value>> symtbl, MyIList<Value> ot, MyIDictionary<StringValue, BufferedReader> fileTable, MyIHeap heap,MyIProcTable procTable){
        exeStack=stk;
        symTable=symtbl;
        this.fileTable=fileTable;
        this.heapTable=heap;
        this.procTable = procTable;
        out = ot;
        id=setId();

    }

    public int getId(){
        return id;
    }

    public static synchronized int setId(){
        lastId++;
        return lastId;
    }


    public String toString(){
        String str = "Program state\n" +
                "Id: "+id+"\n"+
                "Exe Stack: " + exeStack.toString() + " \n" +
                "Sym Table: " + symTable + " \n" +
                "File Table: " + fileTable + "\n" +
                "Heap Table: " + heapTable.toString() + "\n" +
                "Output Console: " + out + " \n"+
                "Procedures Table: " + procTable+"\n";
        return str;
    }
    public MyIStack<IStmt> getExeStk() {
        return exeStack;
    }

    public void setExeStack(MyIStack<IStmt> exeStack){

        this.exeStack = exeStack;
    }

    public MyIStack<MyIDictionary<String, Value>> getSymTable() {

        return symTable;
    }

    public MyIDictionary<String, Value> getTopSymTable() {
        try {
            return symTable.top();
        } catch (RuntimeException e) {
            System.out.println("Stack is empty!");
            return null;
        } catch (ADTException e) {
            throw new RuntimeException(e);
        }
    }

    public void setSymTable(MyIStack<MyIDictionary<String, Value>> symTable) {
        this.symTable = symTable;
    }

    public void setFileTable(MyIDictionary<StringValue, BufferedReader> fileTable){
        this.fileTable=fileTable;
    }

    public MyIDictionary<StringValue, BufferedReader> getFileTable(){
        return this.fileTable;
    }

    public MyIList<Value> getOut(){
        return out;
    }
    public void setOut(MyIList<Value> out){
        this.out=out;
    }

    public MyIHeap getHeap(){
        return heapTable;
    }

    public void setHeapTable(MyIHeap heap){
        this.heapTable=heap;
    }

    public void setProcTable(MyIProcTable procTable) {
        this.procTable = procTable;
    }

    public MyIProcTable getProcTable(){
        return this.procTable;
    }

    public Boolean isNotCompleted(){
        return !exeStack.isEmpty();
    }

    public PrgState oneStep() throws MyException, ADTException, ExprException, StmtException {

          if(exeStack.isEmpty())
              throw new MyException("Prgstate stack is empty");
          IStmt crtStmt = exeStack.pop();
          return crtStmt.execute(this);
    }


}