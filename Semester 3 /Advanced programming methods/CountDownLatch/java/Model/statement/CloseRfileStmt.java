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
        MyIHeap heap=state.getHeap();
        Value val = exp.eval(symTbl,heap);
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

        return null;
    }

    @Override
    public String toString(){
        return String.format("CloseReadfile(%s)",exp.toString());
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type typeexp=exp.typeCheck(typeEnv);
        if(typeexp.equals(new StringType())){
            return typeEnv;
        }
        else throw new MyException("CLOSE: requires a string as expression parameter");
    }

}
