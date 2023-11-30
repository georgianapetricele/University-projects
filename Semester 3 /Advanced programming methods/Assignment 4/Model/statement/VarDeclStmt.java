package Model.statement;
import Exceptions.*;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIStack;
import Model.expression.Exp;
import Model.value.BoolValue;
import Model.value.IntValue;
import Model.value.Value;
import Model.type.*;
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
    public PrgState execute(PrgState state) throws StmtException,ADTException {
        MyIStack<IStmt> stk = state.getStk();
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
        return state;
    }
}