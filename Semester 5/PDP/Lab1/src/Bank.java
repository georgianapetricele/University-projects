import java.util.ArrayList;
import java.util.List;
import java.util.Timer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Bank {
    public static final int NUM_ACCOUNTS = 20;
    public static final int INITIAL_BALANCE = 1000;
    public static final int NUM_OPERATIONS = 100;
    public static List<Account> accounts = new ArrayList<>();
    private static Timer checkerTimer;
    public static volatile boolean operationsCompleted = false;

    public static void main(String[] args) {
        createAccounts();
        for (int numThreads : new int[]{1, 2, 4, 8}) {
            System.out.println("Testing with " + numThreads + " threads:");
            long startTime = System.currentTimeMillis();

            scheduleOperations(numThreads);
            scheduleCheckerTask();

            try {
                Thread.sleep(4000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }

            stopCheckerTask();
            operationsCompleted = true;

            long endTime = System.currentTimeMillis();
            long duration = endTime - startTime;
            System.out.println("Time taken with " + numThreads + " threads: " + duration + " milliseconds");
            System.out.println();

            operationsCompleted = false;
        }
    }

    private static void createAccounts() {
        for (int i = 0; i < NUM_ACCOUNTS; i++) {
            accounts.add(new Account(INITIAL_BALANCE));
        }
    }

    private static void scheduleCheckerTask() {
        checkerTimer = new Timer();
        checkerTimer.schedule(new CheckerTask(), 0, 1000);
    }

    private static void stopCheckerTask() {
        if (checkerTimer != null) {
            checkerTimer.cancel();
            checkerTimer.purge();
        }
    }

    private static void scheduleOperations(int numThreads) {
        ExecutorService executor = Executors.newFixedThreadPool(numThreads);
        for (int i = 0; i < NUM_OPERATIONS; i++) {
            executor.submit(new OperationTask());
        }
        executor.shutdown();
        try {
            executor.awaitTermination(1, TimeUnit.MINUTES);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
