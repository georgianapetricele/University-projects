
package parser;

import DS.Node;
import grammar.Grammar;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.*;


public class ParserOutput {
    Grammar grammar;
    String sequenceFile;
    String outputFile;
    List<Node> parseTree;

    public ParserOutput(Grammar grammar, String sequenceFile, String outputFile) throws IOException {
        this.grammar = grammar;
        this.sequenceFile = readSequence(sequenceFile);
        this.outputFile = outputFile;
        this.parseTree = new ArrayList<>();
    }

    private String readSequence(String sequenceFile) throws IOException {
        StringBuilder seq = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(sequenceFile))) {
            String line;
            while ((line = br.readLine()) != null) {
                seq.append(line.strip());
            }
        }
        return seq.toString();
    }

    public void createParsingTree(List<Object> workingStack) {
        int father = -1;

        // Create nodes for all elements in the working stack
        for (int i = 0; i < workingStack.size(); i++) {
            Object entry = workingStack.get(i);
            if (entry instanceof NonTerminalEntry nonTerminalEntry) {
                this.parseTree.add(new Node(nonTerminalEntry.getNonTerminal()));
                Node node = this.parseTree.get(i);
                node.setProduction(nonTerminalEntry.getIndex());
            } else {
                this.parseTree.add(new Node((String) entry));
            }
        }

        // Set the father and sibling for each node
        for (int i = 0; i < workingStack.size(); i++) {
            Object entry = workingStack.get(i);
            if (entry instanceof NonTerminalEntry nonTerminalEntry) {
                Node node = this.parseTree.get(i);
                node.setFather(father); //assign father based on the most recent parent node
                father = i;


                //get the production length for non-terminal to determine its child nodes.
                int prodLength = this.grammar.getProductions()
                        .get(nonTerminalEntry.getNonTerminal())
                        .get(nonTerminalEntry.getIndex()).size();

                List<Integer> childNodesIndexes = new ArrayList<>();
                for (int j = 1; j <= prodLength; j++) {
                    childNodesIndexes.add(i + j); //add the indexes in the tree of the child nodes
                }


                // Handle indexes if there are nested non-terminals
                for (int j = 0; j < prodLength; j++) {
                    //if the child node is a non-terminal
                    if (this.parseTree.get(childNodesIndexes.get(j)).getProduction() != -1) {
                        int offset = getNestedDepthLength(childNodesIndexes.get(j), workingStack);
                        for (int k = j + 1; k < prodLength; k++) {
                            childNodesIndexes.set(k, childNodesIndexes.get(k) + offset);
                        }
                    }
                }

                // Adjust sibling relationships
                for (int j = 0; j < prodLength-1 ; j++) {
                    this.parseTree.get(childNodesIndexes.get(j)).setSibling(childNodesIndexes.get(j + 1));
                }

            } else {
                Node node = this.parseTree.get(i);
                node.setFather(father);
                father = -1;
            }
        }
    }

    private int getNestedDepthLength(int index, List<Object> workingStack) {
        NonTerminalEntry nonTerminalEntry = (NonTerminalEntry) workingStack.get(index);
        List<String> production = this.grammar.getProductions()
                .get(nonTerminalEntry.getNonTerminal())
                .get(nonTerminalEntry.getIndex());

        int prodLength = production.size();
        int sum = prodLength;
        for (int i = 1; i <= prodLength; i++) {
            if (workingStack.get(index + i) instanceof NonTerminalEntry) {
                sum += getNestedDepthLength(index + i, workingStack);
            }
        }
        return sum;
    }

    public void writeParsingTree(String state, List<Object> working) throws IOException {
        if (!state.equals("e")) {

            String header = String.format("| %-7s | %-7s | %-8s | %-8s |", "index", "value", "father", "sibling");
            String separator = "+---------+---------+----------+----------+";

            System.out.println("\n\nParsing tree:");
            System.out.println(separator);
            System.out.println(header);
            System.out.println(separator);

            for (int index = 0; index < working.size(); index++) {
                Node node = parseTree.get(index);
                String row = String.format("| %-7d | %-7s | %-8d | %-8d |",
                        index,
                        node.getValue(),
                        node.getFather(),
                        node.getSibling());
                System.out.println(row);
                System.out.println(separator);
            }

            try (BufferedWriter writer = Files.newBufferedWriter(Paths.get(outputFile), StandardOpenOption.APPEND)) {
                writer.write("\n\nParsing tree:\n");
                writer.write(separator + "\n");
                writer.write(header + "\n");
                writer.write(separator + "\n");
                for (int index = 0; index < working.size(); index++) {
                    Node node = parseTree.get(index);
                    writer.write(String.format("| %-7d | %-7s | %-8d | %-8d |\n",
                            index,
                            node.getValue(),
                            node.getFather(),
                            node.getSibling()));
                    writer.write(separator + "\n");
                }
            }
        }
    }

}
