package Model.adt;
import Exceptions.ADTException;

import Model.value.Value;

import java.util.HashMap;
import java.util.Map;

public class MyDictionary<K,V> implements MyIDictionary<K,V>{
    Map<K,V> map;

    public MyDictionary(){

        map= new HashMap<>();
    }

    @Override
    public void add(K key,V value) throws ADTException{
        if(map.containsKey(key))
            throw new ADTException("Value already added in the map");
        else
            map.put(key,value);
    }

    @Override
    public V lookup(K key) {

        return map.get(key);
    }

    public void remove(K key){
        map.remove(key);
    }

    @Override
    public boolean isDefined(K key) {

        return map.containsKey(key);
    }

    @Override
    public void update(K key, V val) {
        map.put(key, val);
    }

    public String toString(){
            return this.map.toString();

    }

}
