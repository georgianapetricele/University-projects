public class SymbolTable<T> {

    private final HashTable<T> table;

    public SymbolTable(int capacity){
        this.table = new HashTable<>(capacity);
    }

    public boolean addSymbol(T symbol){
        return table.addElement(symbol);
    }

    public boolean removeSymbol(T symbol){
        return table.removeElement(symbol);
    }

    public boolean containsSymbol(T symbol){
        return table.contains(symbol);
    }

    public Pair<Integer,Integer> getPositionForSymbol(T symbol){
        return table.getPositionForElement(symbol);
    }

    @Override
    public String toString() {
        return this.table.toString();
    }

}
