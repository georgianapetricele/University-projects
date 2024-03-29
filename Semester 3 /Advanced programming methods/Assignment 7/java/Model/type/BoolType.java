package Model.type;

import Model.value.BoolValue;
import Model.value.Value;

public class BoolType implements Type {

    public boolean equals(Object another) {
        if (another instanceof BoolType)
            return true;
        else
            return false;
    }

    public String toString() {
        return "bool";
    }

    @Override
    public Value defaultValue() {
        return new BoolValue(false);
    }

}