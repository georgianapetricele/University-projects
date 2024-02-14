package Model.adt;

import Exceptions.ADTException;

import java.util.Collection;
import java.util.Map;

public interface MyIDictionary<K,V> {

    public void add(K key,V value) throws ADTException;
    public V lookup(K key);

    public Collection<V> getValues();

    public boolean isDefined(K key);

    public void update(K key, V val);

    public String toString();

    public void remove(K key);

    public Map<K,V> getContent();

    public MyIDictionary<K, V> clone();


}
