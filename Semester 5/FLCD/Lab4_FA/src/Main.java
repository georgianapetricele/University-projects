import FA.FiniteAutomata;
import domain.Scanner;
import domain.SymbolTable;

import java.io.IOException;
import java.util.Objects;

public class Main {
    public static void main(String[] args) throws IOException {
        String tokenFile = "src/input/token.in";
        Scanner scanner = new Scanner(tokenFile);

        scanner.scan("p1.txt");
        scanner.scan("p2.txt");
        scanner.scan("p3.txt");
        scanner.scan("p1err.txt");

        var fa = new FiniteAutomata("./src/input/FA.in");
        System.out.println("1. Print states");
        System.out.println("2. Print alphabet");
        System.out.println("3. Print output states");
        System.out.println("4. Print initial state");
        System.out.println("5. Print transitions");
        System.out.println("6. Check if sequence is accepted");
        System.out.println("7. Get matching substring");
        System.out.println("0. Exit");
        while (true) {
            System.out.println();
            System.out.println("Enter your option: ");
            var option = new java.util.Scanner(System.in).nextInt();
            switch (option) {
                case 1:
                    fa.printStates();
                    break;
                case 2:
                    fa.printAlphabet();
                    break;
                case 3:
                    fa.printOutputStates();
                    break;
                case 4:
                    fa.printInitialState();
                    break;
                case 5:
                    fa.printTransitions();
                    break;
                case 6:
                    System.out.println("Enter sequence: ");
                    var word = new java.util.Scanner(System.in).nextLine();
                    if(fa.checkAcceptedSequence(word))
                        System.out.println("Accepted");
                    else
                        System.out.println("Not accepted");
                    break;
                case 7:
                    word = new java.util.Scanner(System.in).nextLine();
                    var accepted = fa.getNextAccepted(word);
                    if (Objects.equals(accepted, "")) {
                        System.out.println("No matching substring");
                    } else {
                        System.out.println(accepted);
                    }
                    break;
                case 0:
                    break;
                default:
                    System.out.println("Invalid option");
            }

        }
    }
}