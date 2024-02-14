package Model.statement;

import Exceptions.ADTException;
import Exceptions.ExprException;
import Exceptions.MyException;
import Exceptions.StmtException;
import Model.PrgState;
import Model.adt.MyIDictionary;
import Model.adt.MyIHeap;
import Model.expression.Exp;
import Model.type.RefType;
import Model.type.Type;
import Model.value.RefValue;
import Model.value.Value;

public class NewHeapStmt implements IStmt{

    String varName;
    Exp exp;

    public NewHeapStmt(String varName,Exp exp){
        this.varName=varName;
        this.exp=exp;
    }


    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {

        MyIDictionary<String, Value> symTbl=state.getSymTable();
        MyIHeap heap =state.getHeap();
        if(!symTbl.isDefined(varName))
            throw new StmtException(String.format("Variable %s isn't in symTable",varName));
        Value varVal = symTbl.lookup(varName);
        if(!(varVal.getType() instanceof RefType))
            throw new StmtException(String.format("Type %s not RefType",varName));

        Value valEval = exp.eval(symTbl,heap);
        Value val2=symTbl.lookup(varName);
        Type locationType=((RefValue)val2).getLocationType();
        if(!(locationType.equals(valEval.getType())))
            throw new StmtException(String.format("Type %s isn't equal to type %s",valEval.getType(),locationType));

        int newPosition = heap.add(valEval);
        symTbl.update(varName,new RefValue(newPosition,locationType));

        state.setSymTable(symTbl);
        state.setHeapTable(heap);
        return null;
    }

    @Override
    public String toString(){
        return "new(" + varName + ", " + exp + ")";
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type typevar = typeEnv.lookup(varName); //get the type of the variable in the type environment
        Type typexp = exp.typeCheck(typeEnv); //get the expression type
        if (typevar.equals(new RefType(typexp)))
            return typeEnv;
        else
            throw new MyException("NEW stmt: right hand side and left hand side have different types ");
    }
}
