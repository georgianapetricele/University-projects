package Model.adt;

import Exceptions.ADTException;

public interface MyIStack<T>{

    public T pop() throws ADTException;
    public void push(T v);
    public boolean isEmpty();

    public String toString();
}