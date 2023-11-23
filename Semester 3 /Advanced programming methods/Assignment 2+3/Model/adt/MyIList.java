package Model.adt;

import Exceptions.ADTException;

public interface MyIList<T> {

    public void add(T elem);
    public void remove(T elem) throws ADTException;
    public int size();
    public T get(int index) throws ADTException;

    public String toString();
}
