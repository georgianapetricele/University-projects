package parser;

import grammar.Grammar;

import java.io.*;
import java.nio.file.*;
import java.util.*;

public class Parser {
    private final Grammar grammar;
    private final List<String> sequence;
    private final String outFile;
    private final List<Object> working;
    private final List<String> input;
    private int index;
    private String state;

    public Parser(Grammar grammar, String sequenceFile, String outFile) throws IOException {
        this.grammar = grammar;
        this.outFile = outFile;
        this.sequence = readSequence(sequenceFile);
        this.working = new ArrayList<>();
        this.input = new ArrayList<>(Collections.singletonList(grammar.getStartSymbol()));
        this.index = 0;
        this.state = "q";
        Files.createDirectories(Paths.get("out"));
        Files.write(Paths.get(outFile), new byte[0]);
    }

    private List<String> readSequence(String seqFile) throws IOException {
        List<String> seq = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(seqFile))) {
            String line;
            while ((line = br.readLine()) != null) {
                seq.add(line.strip());
            }
        }
        return seq;
    }

    public List<Object> getWorkingStack() {
        return working;
    }

    public String getState() {
        return state;
    }

    private void printCurrentTransition() throws IOException {
        String msg = String.format("(%s, %d, %s, %s)\n", state, index, working, input);
        Files.writeString(Paths.get(outFile), msg, StandardOpenOption.APPEND);
        System.out.print(msg);
    }

    // expand the non-terminal from the input stack
    // then add to the input stack the first production of the non-terminal
    // add the non-terminal + prod number to the working stack
    private void expand() throws IOException {
        logAction("expand");
        String nonTerminal = input.remove(0);
        working.add(new NonTerminalEntry(nonTerminal, 0));
        List<String> newProduction = grammar.getProductionsForNonTerminal(nonTerminal).get(0);
        input.addAll(0, newProduction);
    }

    // pass to the next symbol from the input stack
    // transition to another state
    private void advance() throws IOException {
        logAction("advance");
        working.add(input.remove(0));
        index++;
    }

    private void momentaryInsuccess() throws IOException {
        logAction("momentary insuccess");
        state = "b";
    }

    // go back to previous state
    // remove the element from the top of working stack and add it on top of the input stack
    private void back() throws IOException {
        logAction("back");
        input.add(0, (String) working.remove(working.size() - 1));
        index--;
    }

    private void anotherTry() throws IOException {
        logAction("another try");

        if (!working.isEmpty() && working.getLast() instanceof NonTerminalEntry) {
            NonTerminalEntry lastNT = (NonTerminalEntry) working.removeLast();
            String nt = lastNT.getNonTerminal();
            int prodIndex = lastNT.getIndex();

            List<List<String>> productions = grammar.getProductionsForNonTerminal(nt);

            // try next production for the non-terminal if there is one
            if (prodIndex + 1 < productions.size()) {
                state = "q";
                working.add(new NonTerminalEntry(nt, prodIndex + 1));
                List<String> newProduction = productions.get(prodIndex + 1);

                input.subList(0, productions.get(prodIndex).size()).clear();
                input.addAll(0, newProduction);

                // if not remove the symbols from last production
                // if input is not empty add the non-terminal to the input stack
            } else {
                input.subList(0, productions.get(prodIndex).size()).clear();
                if (!input.isEmpty()) {
                    input.add(0, nt);
                }
            }
        } else {
            state = "e";
        }
    }

    private void success() throws IOException {
        logAction("success");
        state = "f";
        System.out.println("Sequence is syntactically correct.");
        Files.writeString(Paths.get(outFile), "Sequence is syntactically correct.\n", StandardOpenOption.APPEND);
    }

    private void error() throws IOException {
        logAction("error");
        state = "e";
    }

    private void logAction(String action) throws IOException {
        String msg = "|--- " + action + "\n";
        Files.writeString(Paths.get(outFile), msg, StandardOpenOption.APPEND);
        System.out.print(msg);
    }

    /*
    expand - when head of input stack is a nonterminal
    advance - when head of input stack is a terminal = current symbol from input
    momentary insuccess - when head of input stack is a terminal != current symbol from input
    back - when head of working stack is a terminal
    another try - when head of working stack is a nonterminal
    success - when input stack is empty and index is at the end of the sequence
     */
    public void run() throws IOException {
        while (!state.equals("f") && !state.equals("e")) {
            printCurrentTransition();
            if (state.equals("q")) {
                if (input.isEmpty() && index == sequence.size())
                    success();
                else
                if (!input.isEmpty() && grammar.getNonTerminals().contains(input.getFirst()))
                    expand();
                else
                if (index < sequence.size() && input.getFirst().equals(sequence.get(index)))
                    advance();
                else momentaryInsuccess();
            } else if (state.equals("b")) {
                if (!working.isEmpty() && grammar.getTerminals().contains(working.getLast().toString()))
                    back();
                else anotherTry();
            }
        }
        if (state.equals("e")) {
            printCurrentTransition();
            error();
        }
    }
}
