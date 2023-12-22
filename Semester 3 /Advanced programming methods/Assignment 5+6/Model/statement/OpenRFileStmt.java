package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.adt.MyIStack;
import Model.type.StringType;
import Model.type.Type;
import Model.value.StringValue;
import Model.value.Value;

import Model.expression.Exp;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class OpenRFileStmt implements IStmt{
    Exp exp;

    public OpenRFileStmt(Exp exp){
        this.exp=exp;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {

        MyIDictionary<String,Value> symTbl = state.getSymTable();
        MyIDictionary<StringValue, BufferedReader> fileTable= state.getFileTable();
        MyIHeap heap=state.getHeap();
        Value val = exp.eval(symTbl,heap);
        if(val.getType().equals(new StringType())){
            StringValue fileName = (StringValue) val;
            if(!(fileTable.isDefined(fileName)))
            {
                BufferedReader br;
                try{
                    br= new BufferedReader(new FileReader(fileName.getVal()));
                }
                catch(IOException e) {
                    throw new StmtException(String.format("File %s couldn't be opened",fileName.getVal()));
                }
                fileTable.add(fileName,br);
                state.setFileTable(fileTable);
            }
            else
                throw new ADTException(String.format("String value %s is already a key in the FileTable",fileName.getVal()));
        }
        else
            throw new StmtException("Expression evaluation doesn't return String type");

        return null;
    }

    @Override
    public String toString(){
        return String.format("OpenReadfile(%s)",exp.toString());
    }

    @Override
    public MyIDictionary<String, Type> typecheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type typeexp=exp.typecheck(typeEnv);
        if(typeexp.equals(new StringType())){
            return typeEnv;
        }
        else throw new MyException("OPEN: requires a string as expression parameter");
    }
}
