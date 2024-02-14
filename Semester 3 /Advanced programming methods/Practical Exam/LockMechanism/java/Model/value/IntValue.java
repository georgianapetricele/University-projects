package Model.value;

import Model.type.IntType;
import Model.type.Type;

public class IntValue implements Value{
    int val;
    public IntValue(int v){
        this.val=v;
    }

    public boolean equals(Value another) {
        if(!(another instanceof IntValue))
            return false;
        IntValue castValue = (IntValue) another;
        return this.val == castValue.val;

    }

    public int getVal() {return val;}
    public String toString() {
        return Integer.toString(val);
    }
    public Type getType() {
        return new IntType();
    }
}
