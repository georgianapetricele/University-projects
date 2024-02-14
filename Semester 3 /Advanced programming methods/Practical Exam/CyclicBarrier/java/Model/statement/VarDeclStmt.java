package Model.statement;

import Exceptions.ADTException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIStack;
import Model.type.Type;
import Model.value.Value;
public class VarDeclStmt implements IStmt {
    String name;
    Type typ;

    public VarDeclStmt(String name,Type typ){
        this.name=name;
        this.typ=typ;
    }

    public Type getTyp(){
        return this.typ;
    }

    @Override
    public String toString(){
        return typ.toString() + " " + name;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        typeEnv.add(name,typ); //add the new pair to the type environment
        return typeEnv;
    }

    @Override
    public PrgState execute(PrgState state) throws StmtException,ADTException {
        MyIStack<IStmt> stk = state.getExeStk();
        MyIDictionary<String, Value> symTbl = state.getSymTable();

        if(symTbl.isDefined(name))
            throw new StmtException("Variable is already declared!");
        else
        {
//            if(typ.equals(new BoolType()))
//                symTbl.add(name,typ.defaultValue());
//            else
//                if(typ.equals(new IntType()))
//                    symTbl.add(name,typ.defaultValue());
//                else
//                    if(typ.equals(new StringType()))
                 symTbl.add(name,typ.defaultValue());
        }
        state.setExeStack(stk);
        state.setSymTable(symTbl);
        return null;
    }
}