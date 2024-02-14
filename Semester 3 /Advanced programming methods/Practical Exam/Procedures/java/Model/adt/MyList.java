package Model.adt;

import Exceptions.ADTException;

import java.util.ArrayList;
import java.util.List;

public class MyList<T> implements MyIList<T> {

    List<T> list;
    public MyList(){

        list = new ArrayList<>();
    }

    @Override
    public void add(T elem){
        synchronized (this) {
            this.list.add(elem);
        }
    }

    @Override
    public void remove(T elem) throws ADTException {
        if(!list.contains(elem))
            throw new ADTException("Element doesn't exist!");
        else
            list.remove(elem);
    }

    @Override
    public int size() {
        return list.size();
    }

    @Override
    public T get(int index) throws ADTException {
        synchronized (this) {
            if (list.isEmpty())
                throw new ADTException("The list is empty!");
        return list.get(index);
    }
    }

    @Override
    public List<T> getList() {
        synchronized (this) {
            return list;
        }
    }

    @Override
    public String toString(){
        return this.list.toString();
    }

}
