package Model.adt;

import Exceptions.ADTException;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

public class MyStack<T> implements MyIStack<T>{

    Stack<T> stack; //sau ArrayDeque

    public MyStack(){
        stack = new Stack<>();
    }

    public Stack<T> getContent(){
        return stack;
    }

    @Override
    public T pop() throws ADTException {
        if(stack.isEmpty())
            throw new ADTException("Stack is empty!");
        return stack.pop();
    }

    @Override
    public List<T> getReversed() {
        List<T> list = Arrays.asList((T[]) stack.toArray());
        Collections.reverse(list);
        return list;
    }

    @Override
    public T top() throws ADTException {
        if(stack.isEmpty())
            throw new ADTException("Stack is empty!");
        return stack.peek();
    }

    @Override
    public void push(T v) {
        stack.push(v);
    }

    @Override
    public boolean isEmpty() {

        return stack.isEmpty();
    }

    public String toString(){
        String str="\n";
        for(int i=stack.size()-1;i>=0;i--)
            str+=stack.get(i).toString()+"\n";
        return str;
    }
}