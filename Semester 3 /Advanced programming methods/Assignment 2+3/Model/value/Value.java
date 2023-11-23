package Model.value;
import Model.type.*;

public interface Value {

    public String toString();

    public Type getType();

    public boolean equals(Value another);

}