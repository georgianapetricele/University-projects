package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.expression.Exp;
import Model.type.IntType;
import Model.type.StringType;
import Model.type.Type;
import Model.value.IntValue;
import Model.value.StringValue;
import Model.value.Value;

import java.io.BufferedReader;
import java.io.IOException;

public class ReadFileStmt implements IStmt{

    private final Exp exp;
    private final String varName;

    public ReadFileStmt(Exp exp,String varName){
        this.exp=exp;
        this.varName=varName;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIDictionary<StringValue,BufferedReader> fileTable= state.getFileTable();
        System.out.println(fileTable.toString());
        MyIHeap heap=state.getHeap();
        Value val1 = symTable.lookup(varName);
        if(symTable.isDefined(varName) ){
            if(val1.getType().equals(new IntType())) {
                Value val = exp.eval(symTable,heap);
                if (val instanceof StringValue) {
                    StringValue castval = (StringValue) val;
                    if(fileTable.isDefined(castval))
                    {
                        BufferedReader br;
                        try {
                            br = fileTable.lookup(castval);
                            String line=br.readLine();
                            if(line==null)
                                line="0";
                            symTable.update(varName,new IntValue(Integer.parseInt(line)));
                        }
                        catch (IOException e) {
                            throw new StmtException(String.format("Could not read from file %s",castval.getVal()));
                        }
                    }
                    else
                        throw new StmtException(String.format("File %s doesn't exit in the file table", castval.getVal()));

                } else
                    throw new ExprException(String.format("The expression %s couldn't be eval to string value",exp.toString()));
            }
            else
                throw new StmtException(String.format("The value %s is not of type int",val1));
        }
        else
            throw new ADTException(String.format("The variable %s is not defined in symTable",varName));
        return null;
    }

    @Override
    public String toString(){
        return String.format("ReadFile(%s, %s)", exp.toString(), varName);
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type typeexp=exp.typeCheck(typeEnv);
        if(typeexp.equals(new StringType())){
            Type typevar = typeEnv.lookup(varName);
            if(typevar.equals(new IntType())){
                    return typeEnv;
            }
            else throw new MyException("READ: requires an int as variable's type");
        }
        else throw new MyException("READ: requires a string as expression parameter");
    }
}
