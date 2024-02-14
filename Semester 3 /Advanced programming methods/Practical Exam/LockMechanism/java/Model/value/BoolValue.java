package Model.value;

import Model.type.BoolType;
import Model.type.Type;

public class BoolValue implements Value{

    boolean val;
    public BoolValue(boolean val){
        this.val = val;
    }

    public boolean equals(Value another){
        if(!(another instanceof BoolValue))
            return false;
        BoolValue castValue = (BoolValue) another;
        return this.val == castValue.val;
    }

    @Override
    public String toString(){
        if(val==true)
            return "true";
        else
            return "false";

    }
    public boolean getVal(){
        return this.val;
    }

    public Type getType(){
        return new BoolType();
    }

}
