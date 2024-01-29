package Model.value;

import Model.type.StringType;
import Model.type.Type;

public class StringValue implements Value {
    String val;

    public StringValue(String value){
        this.val=value;
    }

    @Override
    public boolean equals(Object anotherValue) {
        if (!(anotherValue instanceof StringValue castValue))
            return false;
        return this.val.equals(castValue.val);
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
