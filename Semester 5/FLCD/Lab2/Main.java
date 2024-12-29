public class Main {
    public static void main(String[] args) {

        SymbolTable<String> symbolTable = new SymbolTable<>(20);

        String[] symbols = {"a","aaa","_c2","1","100","Ceva string","b1"};

        System.out.println("Add symbols to the symbol table");
        for (String symbol : symbols) {
            System.out.println(symbolTable.addSymbol(symbol));
        }

        System.out.println("\nCurrent symbol table: ");

        System.out.println(symbolTable);

        System.out.println("\nPositions for all elements: ");
        for (String symbol : symbols) {
            System.out.println("Position of " + symbol + " in the symbolTable is " + symbolTable.getPositionForSymbol(symbol));
        }

        System.out.println("\nCheck if \"aaa\" was added successfully ");
        System.out.println("Elements exists in the symbol table:");
        System.out.println(symbolTable.containsSymbol("aaa"));

        System.out.println("\nRemove \"aaa\": ");
        System.out.println(symbolTable.removeSymbol("aaa"));

        System.out.println("\nCheck if \"aaa\" was removed successfully ");
        System.out.println("Elements exists in the symbol table:");
        System.out.println(symbolTable.containsSymbol("aaa"));


    }
}