package Model.adt;

import Exceptions.ADTException;
import Model.value.Value;

import java.util.HashMap;
import java.util.Set;

public interface MyIHeap{
    int getFreeLocationVal();
    HashMap<Integer, Value> getContent();
    void setContent(HashMap<Integer, Value> newMap);
    int add(Value value);
    void update(Integer position, Value value) throws ADTException;
    Value get(Integer position) throws ADTException;
    boolean containsKey(Integer position);
    void remove(Integer key) throws ADTException;
    Set<Integer> keySet();
}
