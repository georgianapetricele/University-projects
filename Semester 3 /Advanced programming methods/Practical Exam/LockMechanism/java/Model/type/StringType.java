package Model.type;

import Model.value.StringValue;
import Model.value.Value;

public class StringType implements Type{

    public boolean equals(Object another){
        if(another instanceof StringType)
            return true;
        else
            return false;
    }
    public String toString(){
        return "string";
    }
    public Value defaultValue(){
        return new StringValue("");
    }

}
