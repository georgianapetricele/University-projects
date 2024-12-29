

import algorithms.ParallelClassic;
import algorithms.ParallelKaratsuba;
import algorithms.SequentialClassic;
import algorithms.SequentialKaratsuba;
import enums.AlgorithmChoice;
import enums.MethodChoice;
import model.Polynomial;

import java.util.Scanner;
import java.util.concurrent.ExecutionException;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
    private static final MethodChoice METHOD = MethodChoice.PARALLEL;
    private static final AlgorithmChoice ALGORITHM = AlgorithmChoice.KARATSUBA;

    /*
    for 10000 and 20000
    - sequential karatsuba - 1.63 seconds
    - parallel karatsuba - 1.14 seconds
    - sequential classic - 2.117 seconds
    - parallel classic - 1.51 seconds

     */


    public static void main(String[] args) throws ExecutionException, InterruptedException, IOException {
        Polynomial p1 = new Polynomial(1000);
        //System.out.println("p1=" + p1);
        Polynomial p2 = new Polynomial(1000);
        //System.out.println("p2=" + p2);
        long startTime = System.currentTimeMillis();
        run(p1, p2);
        long endTime = System.currentTimeMillis();
        double duration = endTime - startTime;
        BufferedWriter out = new BufferedWriter(
                new FileWriter("results.txt", true));
        out.write(String.format("Duration for %s - degree %s and %s: %s seconds", METHOD + " " + ALGORITHM, p1.getDegree(), p2.getDegree(),duration));
        out.newLine();
        out.close();
        System.out.println("Duration: " + duration + " ms");
    }

    private static void run(Polynomial p1, Polynomial p2) throws InterruptedException, ExecutionException {
        Polynomial result;
        switch (METHOD) {
            case SEQUENTIAL:
                if (ALGORITHM.equals(AlgorithmChoice.CLASSIC)) {
                    result = SequentialClassic.multiply(p1, p2);
                } else {
                    result = SequentialKaratsuba.multiply(p1, p2);
                }
                break;
            case PARALLEL:
                if (ALGORITHM.equals(AlgorithmChoice.CLASSIC)) {
                    result = ParallelClassic.multiply(p1, p2);
                } else {
                    result = ParallelKaratsuba.multiply(p1, p2, 1);
                }
                break;
            default:
                throw new IllegalStateException("Unexpected value: " + METHOD);
        }
        //System.out.println("result=" + result);
    }
}