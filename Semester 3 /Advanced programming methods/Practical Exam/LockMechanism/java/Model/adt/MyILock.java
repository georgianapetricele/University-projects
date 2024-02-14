package Model.adt;

import Exceptions.MyException;

import java.util.HashMap;
import java.util.Set;

public interface MyILock {
    int getFreeValue();
    void put(int key, int value) throws MyException;
    HashMap<Integer, Integer> getContent();
    boolean containsKey(int position);
    int get(int position) throws MyException;
    void update(int position, int value) throws MyException;
    void setContent(HashMap<Integer, Integer> newMap);
    Set<Integer> keySet();
}
