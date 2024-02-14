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

public class writeHStmt implements IStmt{
    String varName;
    Exp exp;

    public writeHStmt(String varName,Exp exp){
        this.varName=varName;
        this.exp=exp;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException, StmtException, ExprException, ADTException {
        MyIDictionary<String, Value> symTbl=state.getSymTable();
        MyIHeap heap = state.getHeap();

        if(!symTbl.isDefined(varName))
            throw new StmtException(String.format("%s not in the symTable",varName));
        Value val=symTbl.lookup(varName);
        if(!(val.getType() instanceof RefType))
            throw new StmtException(String.format("Value %s not of RefType",val.toString()));
        RefValue refVal=(RefValue) val;
        int address=refVal.getAddr();
        if(!heap.containsKey(address))
            throw new ADTException(String.format("Key %d not in the heap",address));
        Value valExp = exp.eval(symTbl,heap);
        if(!(valExp.getType().equals(refVal.getLocationType())))
            throw new StmtException(String.format("Result % of exp not of %s type",valExp.toString(),refVal.getLocationType().toString()));

        heap.update(address,valExp);
        state.setHeapTable(heap);
        return null;

    }

    @Override
    public String toString() {
        return String.format("WriteHeap(%s, %s)", varName, exp);
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException, ADTException {
        Type typevar = typeEnv.lookup(varName);
        Type typeexp = exp.typeCheck(typeEnv);
        if(typevar.equals(new RefType(typeexp))){
            return typeEnv;
        }
        else throw new MyException("WRITE heap stmt: right hand side and left hand side have different types ");
    }
}
