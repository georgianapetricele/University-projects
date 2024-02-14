package Model.adt;

import Exceptions.MyException;

import java.util.HashMap;
import java.util.List;

public class MySemaphore implements MyISemaphore{

    private HashMap<Integer, Tuple<Integer, List<Integer>, Integer>> semaphoreTable;
    private int freeLocation = 0;

    public MySemaphore() {
        this.semaphoreTable = new HashMap<>();
    }
    @Override
    public void put(int key, Tuple<Integer, List<Integer>, Integer> value) throws MyException {
        synchronized (this) {
            if (!semaphoreTable.containsKey(key)) {
                semaphoreTable.put(key, value);
            } else {
                throw new MyException(String.format("Toy semaphore table already contains the key %d!", key));
            }
        }
    }

    @Override
    public Tuple<Integer, List<Integer>, Integer> get(int key) throws MyException {
        synchronized (this) {
            if (semaphoreTable.containsKey(key)) {
                return semaphoreTable.get(key);
            } else {
                throw new MyException(String.format("Toy semaphore table doesn't contain the key %d!", key));
            }
        }
    }

    @Override
    public boolean containsKey(int key) {
        synchronized (this) {
            return semaphoreTable.containsKey(key);
        }
    }

    @Override
    public int getFreeAddress() {
        synchronized (this) {
            freeLocation++;
            return freeLocation;
        }
    }

    @Override
    public void setFreeAddress(int freeAddress) {
        synchronized (this) {
            this.freeLocation = freeAddress;
        }
    }

    @Override
    public void update(int key, Tuple<Integer, List<Integer>, Integer> value) throws MyException {
        synchronized (this) {
            if (semaphoreTable.containsKey(key)) {
                semaphoreTable.replace(key, value);
            } else {
                throw new MyException(String.format("Toy semaphore table doesn't contain key %d!", key));
            }
        }
    }

    @Override
    public HashMap<Integer, Tuple<Integer, List<Integer>, Integer>> getSemaphoreTable() {
        synchronized (this) {
            return semaphoreTable;
        }
    }

    @Override
    public void setSemaphoreTable(HashMap<Integer, Tuple<Integer, List<Integer>, Integer>> newToySemaphoreTable) {
        synchronized (this) {
            this.semaphoreTable = newToySemaphoreTable;
        }
    }

    @Override
    public String toString() {
        return semaphoreTable.toString();
    }
}
