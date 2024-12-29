import grammar.Grammar;
import parser.Parser;
import parser.ParserOutput;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import java.io.IOException;
import java.util.regex.Pattern;

public class Main {

    public static void main(String[] args) throws IOException {

        while (true) {
            Grammar grammar = new Grammar();
            Parser parser = null;
            System.out.println("\n\nChoose an option:");
            System.out.println("1. Run sequence 1");
            System.out.println("2. Run sequence 2");
            System.out.println("0. Quit");

            String choice = new java.util.Scanner(System.in).nextLine();
            String sequenceFile = "";
            String grammarFile = "";
            String outputFile = "";

            switch (choice) {
                case "1":
                    sequenceFile = "src/inputFiles/seq1.txt";
                    grammarFile = "src/inputFiles/g1.txt";
                    outputFile = "src/outputFiles/out1.txt";
                    break;
                case "2":
                    sequenceFile = "src/inputFiles/PIF.out";
                    grammarFile = "src/inputFiles/g2.txt";
                    outputFile = "src/outputFiles/out2.txt";
                    break;
                case "0":
                    return;
                default:
                    System.out.println("Invalid choice.");
                    continue;
            }

            grammar.readFromFile(grammarFile);
            parser = new Parser(grammar, sequenceFile,outputFile);
            parser.run();

            ParserOutput parserOutput = new ParserOutput(grammar, sequenceFile, outputFile);
            parserOutput.createParsingTree(parser.getWorkingStack());
            parserOutput.writeParsingTree(parser.getState(), parser.getWorkingStack());

        }
    }
}
