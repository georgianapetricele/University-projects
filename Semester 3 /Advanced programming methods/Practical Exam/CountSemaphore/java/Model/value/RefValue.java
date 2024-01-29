package Model.value;

import Model.type.RefType;
import Model.type.Type;

public class RefValue implements Value{
    int address;
    Type locationType;

    public RefValue(int address,Type locationType)
    {
        this.address=address;
        this.locationType=locationType;
    }

    public int getAddr() {return address;}

    public Type getType() { return new RefType(locationType);}

    public Type getLocationType(){
        return locationType;
    }

    @Override
    public String toString() {
        return "(" + address + ", " + locationType + ")";
    }

}
