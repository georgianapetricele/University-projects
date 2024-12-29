import domain.Scanner;
import domain.SymbolTable;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        String tokenFile = "src/input/token.in";
        Scanner scanner = new Scanner(tokenFile);

        scanner.scan("p1.txt");
        scanner.scan("p2.txt");
        scanner.scan("p3.txt");
        scanner.scan("p1err.txt");

    }
}