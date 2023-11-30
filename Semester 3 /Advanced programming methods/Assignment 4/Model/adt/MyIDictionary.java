package Model.adt;

import Exceptions.ADTException;
import Model.value.Value;

import java.util.HashMap;
import java.util.Map;

public interface MyIDictionary<K,V> {

    public void add(K key,V value) throws ADTException;
    public V lookup(K key);

    public boolean isDefined(K key);

    public void update(K key, V val);

    public String toString();

    public void remove(K key);

    Map<K,V> getContent() throws ADTException;


}
