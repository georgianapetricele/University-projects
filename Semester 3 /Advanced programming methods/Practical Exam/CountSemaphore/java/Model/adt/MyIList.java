package Model.adt;

import Exceptions.ADTException;

import java.util.List;

public interface MyIList<T> {

    public void add(T elem);
    public void remove(T elem) throws ADTException;
    public int size();
    public T get(int index) throws ADTException;

    List<T> getList();

    public String toString();
}
