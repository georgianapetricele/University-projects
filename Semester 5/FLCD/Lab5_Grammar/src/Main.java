import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Grammar g = new Grammar();


        try {
            //String filePath = "src/inputFiles/g2.txt";
            //String filePath = "src/inputFiles/g0.txt";
            String filePath = "src/inputFiles/g1.txt";
            g.readGrammar(filePath);
            g.checkCFG();
            g.validate();
            System.out.println("Grammar loaded and checked.");
        } catch (Exception e) {
            System.out.println("Error reading grammar: " + e.getMessage());
            return;
        }

        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Print set of non-terminals");
            System.out.println("2. Print set of terminals");
            System.out.println("3. Print set of productions");
            System.out.println("4. Print productions for a given non-terminal");
            System.out.println("5. Check if the grammar is a valid CFG");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();
            scanner.nextLine();

            try {
                switch (choice) {
                    case 1:
                        System.out.println("Non-terminals: " + g.nonTerminals);
                        break;
                    case 2:
                        System.out.println("Terminals: " + g.terminals);
                        break;
                    case 3:
                        System.out.println("Production Rules: ");
                        g.productionRules.forEach((key, value) -> {
                            System.out.println(key + " -> " + value);
                        });
                        break;
                    case 4:
                        System.out.print("Enter the non-terminal to get its productions: ");
                        String nonTerminal = scanner.nextLine();
                        Map<List<String>, List<List<String>>> filteredProductions = g.filterProductionsByNonTerminal(nonTerminal);
                        if (filteredProductions.isEmpty()) {
                            System.out.println("No productions found for non-terminal: " + nonTerminal);
                        } else {
                            filteredProductions.forEach((key, value) -> {
                                System.out.println(key + " -> " + value);
                            });
                        }
                        break;
                    case 5:
                        try {
                            g.checkCFG();
                            System.out.println("The grammar is a valid CFG.");
                        } catch (Exception e) {
                            System.out.println("Invalid CFG: " + e.getMessage());
                        }
                        break;
                    case 6:
                        System.out.println("Exiting...");
                        scanner.close();
                        return;
                    default:
                        System.out.println("Invalid choice, please try again.");
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }

            System.out.println();
        }
    }
}
