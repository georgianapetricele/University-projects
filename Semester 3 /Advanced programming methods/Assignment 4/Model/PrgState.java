package Model;
import Model.value.*;
import Model.statement.*;
import Model.adt.*;

import java.io.BufferedReader;


public class PrgState{
    MyIStack<IStmt> exeStack;
    MyIDictionary<String, Value> symTable;
    MyIDictionary<StringValue,BufferedReader> fileTable;

    MyIHeap heapTable;

    MyIList<Value> out;
    IStmt originalProgram; //optional field, but good to have
    public PrgState(MyIStack<IStmt> stk, MyIDictionary<String, Value> symtbl, MyIList<Value> ot, MyIDictionary<StringValue, BufferedReader> fileTable, MyIHeap heap,IStmt prg){
        exeStack=stk;
        symTable=symtbl;
        this.fileTable=fileTable;
        this.heapTable=heap;
        out = ot;
        originalProgram=prg;//recreate the entire original prg
        stk.push(prg);

    }


    public String toString(){
        String str = "Program state\n" +
                "Exe Stack: " + exeStack.toString() + " \n" +
                "Sym Table: " + symTable + " \n" +
                "File Table: " + fileTable + "\n" +
                "Heap Table: " + heapTable.toString() + "\n" +
                "Output Console: " + out + " \n";
        return str;
    }
    public MyIStack<IStmt> getStk() {
        return exeStack;
    }

    public void setExeStack(MyIStack<IStmt> exeStack){

        this.exeStack = exeStack;
    }

    public MyIDictionary<String, Value> getSymTable() {

        return symTable;
    }

    public void setSymTable(MyIDictionary<String, Value> symTable) {
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
}