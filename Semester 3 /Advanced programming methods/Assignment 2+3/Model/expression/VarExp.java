package Model.expression;
import Model.adt.MyIDictionary;
import Model.value.*;
import Exceptions.*;

public class VarExp implements Exp{
    String id;

    public VarExp(String id){
        this.id=id;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> tbl) throws ExprException {
        return tbl.lookup(id);
    }

    public String toString(){
        return id;
    }
}