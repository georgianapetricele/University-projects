package Model.type;

import Model.value.Value;

public interface Type{

    public boolean equals(Object another);
    public String toString();
    public Value defaultValue();
}

