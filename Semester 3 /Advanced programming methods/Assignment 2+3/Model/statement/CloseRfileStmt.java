package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.expression.*;
import Model.type.StringType;
import Model.value.StringValue;
import Model.value.Value;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class CloseRfileStmt implements IStmt{

    Exp exp;

    public CloseRfileStmt(Exp exp){
        this.exp=exp;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {

        MyIDictionary<String, Value> symTbl = state.getSymTable();
        MyIDictionary<StringValue, BufferedReader> fileTable= state.getFileTable();
        Value val = exp.eval(symTbl);
        if(val.getType().equals(new StringType())){
            StringValue fileName = (StringValue) val;
            if(fileTable.isDefined(fileName))
            {
                BufferedReader br;
                br = fileTable.lookup(fileName);
                try{
                    br.close();
                }
                catch(IOException e) {
                    throw new StmtException(String.format("Error in closing %s", fileName.getVal()));
                }
                fileTable.remove(fileName);
                state.setFileTable(fileTable);

            }
            else
                throw new ADTException(String.format("String value %s isn't a  key in the FileTable",fileName.getVal()));
        }
        else
            throw new StmtException("Expression evaluation doesn't return String type");

        return state;
    }

    @Override
    public String toString(){
        return String.format("CloseReadfile(%s)",exp.toString());
    }

}
