import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {

        while (true) {
            Grammar grammar = new Grammar();
            Parser parser = null;
            System.out.println("Choose an option:");
            System.out.println("1. Run sequence 1");
            System.out.println("2. Run sequence 2");
            System.out.println("0. Quit");

            String choice = new java.util.Scanner(System.in).nextLine();
            String sequenceFile = "";
            String grammarFile = "";

            switch (choice) {
                case "1":
                    sequenceFile = "src/inputFiles/seq1.txt";
                    grammarFile = "src/inputFiles/g0.txt";
                    break;
                case "2":
                    sequenceFile = "src/inputFiles/seq2.txt";
                    grammarFile = "src/inputFiles/g1.txt";
                    break;
                case "0":
                    return;
                default:
                    System.out.println("Invalid choice.");
                    continue;
            }

            grammar.readFromFile(grammarFile);
            parser = new Parser(grammar, sequenceFile, "parser_out.txt");
            parser.run();
        }
    }
}
