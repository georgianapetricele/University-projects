import model.Matrix;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of rows for matrix A:");
        int rowsA = scanner.nextInt();
        System.out.println("Enter the number of columns for matrix A:");
        int colsA = scanner.nextInt();
        System.out.println("Enter the number of rows for matrix B:");
        int rowsB = scanner.nextInt();
        System.out.println("Enter the number of columns for matrix B:");
        int colsB = scanner.nextInt();

        if (colsA != rowsB) {
            System.out.println("Cannot multiply matrices - the number of columns in A must match the number of rows in B.");
            return;
        }

        Matrix A = new Matrix(rowsA, colsA);
        Matrix B = new Matrix(rowsB, colsB);
        Matrix C = new Matrix(rowsA, colsB);

        System.out.println("Matrix A:");
        System.out.println(A);
        System.out.println("Matrix B:");
        System.out.println(B);


        System.out.println("Enter the number of threads:");
        int nrThreads = scanner.nextInt();
       while(true){
           System.out.println("Enter the generation strategy:");
           System.out.println("1. ROWS");
           System.out.println("2. COLUMNS");
           System.out.println("3. KTH");
           System.out.println("0. Exit");
           String genStrategy = scanner.next();
              if(genStrategy.equals("0")) {
                  break;
              }
              else
              {
                  MatrixMultiplier multiplier = new MatrixMultiplier(A, B, C, nrThreads, genStrategy);

                  System.out.println("\nRunning classic threads approach...");
                  multiplier.classicThreadsDriver();

                  System.out.println("\nRunning thread pool approach...");
                  multiplier.threadPoolDriver();
              }
       }
    }
}
