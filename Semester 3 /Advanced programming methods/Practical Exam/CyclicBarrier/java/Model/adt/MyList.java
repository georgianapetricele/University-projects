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
        list.add(elem);
    }

    @Override
    public List<T> getList() {
        synchronized (this) {
            return list;
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
        return list.get(index);
    }

    @Override
    public String toString(){
        return this.list.toString();
    }

}
