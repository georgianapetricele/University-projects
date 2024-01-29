package Model.adt;

import Exceptions.ADTException;
import Model.value.Value;

import java.util.HashMap;
import java.util.Set;

public class MyHeap implements MyIHeap{

    HashMap<Integer, Value> heap;
    Integer freeLocation;
    public MyHeap(){
        this.heap=new HashMap<>();
        this.freeLocation =1;
    }


    @Override
    public int getFreeLocationVal() {
        return freeLocation;
    }

    public Integer newFreeLocation(){
        freeLocation++;
        while(freeLocation==0||heap.containsKey(freeLocation))
            freeLocation++;
        return freeLocation;
    }

    @Override
    public HashMap<Integer, Value> getContent() {
        return heap;
    }

    @Override
    public void setContent(HashMap<Integer, Value> newMap) {
        this.heap=newMap;
    }

    @Override
    public int add(Value value) {
        heap.put(freeLocation,value);
        Integer currentLocVal=freeLocation;
        Integer newVal=newFreeLocation();
        return currentLocVal;
    }

    @Override
    public void update(Integer address, Value value) throws ADTException {
        if(!heap.containsKey(address))
            throw new ADTException(String.format("Unexistent location %d",address));
        heap.put(address,value);
    }

    @Override
    public Value get(Integer address) throws ADTException {
        if(!heap.containsKey(address))
            throw new ADTException(String.format("Unexistent location %d",address));
        return heap.get(address);
    }

    @Override
    public boolean containsKey(Integer address) {
        return heap.containsKey(address);
    }

    @Override
    public void remove(Integer key) throws ADTException {
            if(!heap.containsKey(key))
                throw new ADTException(String.format("%d is not defined",key));
            freeLocation=key;
            heap.remove(key);
    }

    @Override
    public Set<Integer> keySet() {
        return heap.keySet();
    }

    public String toString(){
        String str="{";
        for(Integer key :heap.keySet()){
            str+=key.toString() + "->" + heap.get(key).toString() + "; ";
        }
        str+="}";
        return str;
    }
}
