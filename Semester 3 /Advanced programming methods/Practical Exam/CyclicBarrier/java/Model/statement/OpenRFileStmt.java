package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.expression.Exp;
import Model.type.StringType;
import Model.type.Type;
import Model.value.StringValue;
import Model.value.Value;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class OpenRFileStmt implements IStmt{
    Exp exp;

    public OpenRFileStmt(Exp exp){
        this.exp=exp;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        MyIDictionary<StringValue, BufferedReader> files=state.getFileTable();
        MyIDictionary<String, Value> table=state.getSymTable();
        MyIHeap heap=state.getHeap();

        try {
            StringValue filestr=(StringValue)exp.eval(table,heap);

            System.out.println(filestr);
            String file = filestr.getVal();
            Type type = exp.eval(table,heap).getType();


            if (!(type.equals(new StringType()))) {
                throw new StmtException("Invalid type");
            }

            if (files.isDefined(filestr)) {
                throw new StmtException("Key already exists");
            }

            BufferedReader r = new BufferedReader(new FileReader(file.toString()));
            files.add(filestr,r);


        }catch(IOException  e){
            throw new StmtException(e.getMessage());
        }

        return null;
    }

    @Override
    public String toString(){
        return String.format("OpenReadfile(%s)",exp.toString());
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type typeexp=exp.typeCheck(typeEnv);
        if(typeexp.equals(new StringType())){
            return typeEnv;
        }
        else throw new MyException("OPEN: requires a string as expression parameter");
    }
}
