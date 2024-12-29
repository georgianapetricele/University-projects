import java.util.ArrayList;

public class HashTable<T> {
    private final int capacity;
    private final ArrayList<ArrayList<T>> hashTable;

    public HashTable(int capacity) {
        this.capacity = capacity;
        this.hashTable = new ArrayList<>(capacity);
        for (int i = 0; i < capacity; i++) {
            hashTable.add(new ArrayList<>());
        }
    }

    public int getCapacity() {
        return capacity;
    }

    /*
    Hash function - Sum of ASCII codes of the characters % capacity
    */
    public int hashFunction(T key) {
        String keyString = key.toString();
        int sum = 0;
        for (int i = 0; i < keyString.length(); i++) {
            sum += keyString.charAt(i);
        }
        return sum % capacity;
    }

    public boolean contains(T key) {
        int hashValue = hashFunction(key);
        return hashTable.get(hashValue).contains(key);
    }

    public boolean addElement(T key) {
        int hashValue = hashFunction(key);

        if (hashTable.get(hashValue).contains(key)) {
            return false;
        }

        return hashTable.get(hashValue).add(key);
    }

    public boolean removeElement(T key) {
        int hashValue = hashFunction(key);

        if (!hashTable.get(hashValue).contains(key)) {
            return false;
        }

        return hashTable.get(hashValue).remove(key);
    }

    public Pair<Integer, Integer> getPositionForElement(T key) {
        if (!contains(key))
            return null;

        int hashValue = hashFunction(key);
        return new Pair<>(hashValue, hashTable.get(hashValue).indexOf(key));
    }


    @Override
    public String toString() {
        StringBuilder output = new StringBuilder();
        for (int i = 0; i < capacity; i++) {
            output.append(i);
            for (T key : hashTable.get(i)) {
                output.append(" --> ").append(key);
            }
            output.append("\n");
        }
        return output.toString();
    }
}