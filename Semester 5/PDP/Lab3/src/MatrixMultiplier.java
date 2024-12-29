import model.Matrix;
import tasks.ColumnTask;
import tasks.KTask;
import tasks.MatrixTask;
import tasks.RowTask;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class MatrixMultiplier {
    private final Matrix A;
    private final Matrix B;
    private final Matrix C;
    private final int nrThreads;
    private final String genStrategy;

    public MatrixMultiplier(Matrix A, Matrix B, Matrix C, int nrThreads, String genStrategy) {
        this.A = A;
        this.B = B;
        this.C = C;
        this.nrThreads = nrThreads;
        this.genStrategy = genStrategy;
    }

    public MatrixTask initRowTask(int index, Matrix A, Matrix B, Matrix C, int nrThreads) {
        int sizeC = C.rows() * C.columns();
        int count = sizeC / nrThreads;

        int startRow = count * index / C.rows();
        int startCol = count * index % C.rows();

        if (index == nrThreads - 1)
            count += sizeC % nrThreads;

        return new RowTask(startRow, startCol, count, A, B, C);
    }

    public MatrixTask initColumnTask(int index, Matrix A, Matrix B, Matrix C, int nrThreads) {
        int sizeC = C.rows() * C.columns();
        int count = sizeC / nrThreads;

        int startRow = count * index % C.rows();
        int startCol = count * index / C.rows();

        if (index == nrThreads - 1)
            count += sizeC % nrThreads;

        return new ColumnTask(startRow, startCol, count, A, B, C);
    }

    public MatrixTask initKTask(int index, Matrix A, Matrix B, Matrix C, int nrThreads) {
        int sizeC = C.rows() * C.columns();
        int count = sizeC / nrThreads;

        if (index < sizeC % nrThreads)
            count++;

        int startRow = index / C.columns();
        int startCol = index % C.rows();

        return new KTask(startRow, startCol, count, nrThreads, A, B, C);
    }

    public void classicThreadsDriver() {
        double startTime = System.nanoTime();
        List<Thread> threads = new ArrayList<>();

        switch (genStrategy) {
            case "1":
                for (int i = 0; i < nrThreads; ++i) {
                    threads.add(initRowTask(i, A, B, C, nrThreads));
                }
                break;
            case "2":
                for (int i = 0; i < nrThreads; ++i) {
                    threads.add(initColumnTask(i, A, B, C, nrThreads));
                }
                break;
            case "3":
                for (int i = 0; i < nrThreads; ++i) {
                    threads.add(initKTask(i, A, B, C, nrThreads));
                }
                break;
            default:
                System.out.println("Wrong matrix generation strategy");
                return;
        }

        for (Thread thread : threads) {
            thread.start();
        }

        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println("Resulting Matrix C:");
        System.out.println(C);
        double stopTime = System.nanoTime();
        double totalTime = (stopTime - startTime) / 1_000_000_000.0;
        System.out.println("Elapsed running time: " + totalTime + "s");
    }

    public void threadPoolDriver() {
        double startTime = System.nanoTime();
        ExecutorService executorService = new ThreadPoolExecutor(
                nrThreads,
                nrThreads,
                0L,
                TimeUnit.MILLISECONDS,
                new ArrayBlockingQueue<>(nrThreads, true)
        );

        switch (genStrategy) {
            case "1":
                for (int i = 0; i < nrThreads; ++i) {
                    executorService.submit(initRowTask(i, A, B, C, nrThreads));
                }
                break;
            case "2":
                for (int i = 0; i < nrThreads; ++i) {
                    executorService.submit(initColumnTask(i, A, B, C, nrThreads));
                }
                break;
            case "3":
                for (int i = 0; i < nrThreads; ++i) {
                    executorService.submit(initKTask(i, A, B, C, nrThreads));
                }
                break;
            default:
                System.out.println("Wrong matrix generation strategy");
                return;

        }

        executorService.shutdown();
        try {
            if (!executorService.awaitTermination(300, TimeUnit.SECONDS)) {
                executorService.shutdownNow();
            }
            System.out.println("Resulting Matrix C:");
            System.out.println(C);
            double stopTime = System.nanoTime();
            double totalTime = (stopTime - startTime) / 1_000_000_000.0;
            System.out.println("Elapsed running time: " + totalTime + "s");
        } catch (InterruptedException ex) {
            executorService.shutdownNow();
            Thread.currentThread().interrupt();
        }
    }
}
