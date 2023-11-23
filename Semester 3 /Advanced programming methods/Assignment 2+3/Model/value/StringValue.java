package Model.value;

import Model.type.StringType;
import Model.type.Type;

public class StringValue implements Value {
    String val;

    public StringValue(String value){
        this.val=value;
    }

    @Override
    public boolean equals(Value another) {
        if(!(another instanceof StringValue))
            return false;
        StringValue castValue = (StringValue) another;
        return this.val == castValue.val;
    }

    public String getVal(){
        return this.val;
    }
    public String toString(){
        return val;
    }

    public Type getType(){
        return new StringType();
    }
}
