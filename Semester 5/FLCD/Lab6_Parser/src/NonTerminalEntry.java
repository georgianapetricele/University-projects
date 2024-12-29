public class NonTerminalEntry {
    private String nonTerminal;
    private int index;

    public NonTerminalEntry(String nonTerminal, int index) {
        this.nonTerminal = nonTerminal;
        this.index = index;
    }

    public String getNonTerminal() {
        return nonTerminal;
    }

    public int getIndex() {
        return index;
    }

    @Override
    public String toString() {
        return "(" + nonTerminal + ", " + index + ")";
    }
}
