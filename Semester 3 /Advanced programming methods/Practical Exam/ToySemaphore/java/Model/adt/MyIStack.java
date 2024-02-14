package Model.adt;

import Exceptions.ADTException;

import java.util.List;
import java.util.Stack;

public interface MyIStack<T>{

    public T pop() throws ADTException;

    public T top() throws ADTException;
    public void push(T v);
    public boolean isEmpty();

    public Stack<T> getContent();

    List<T> getReversed();
    public String toString();
}