import mpi.MPI;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        MPI.Init(args);

        int rank = MPI.COMM_WORLD.Rank();
        int size = MPI.COMM_WORLD.Size();

        DSMSystem dsm = new DSMSystem();

        System.out.println("Starting process <" + rank + ">");

        if (rank == 0) {

            // run the subscriber thread to listen for messages
            Thread thread = new Thread(new Subscriber(dsm));
            thread.start();

            dsm.subscribeToVariable("a");
            Thread.sleep(1000);
            dsm.subscribeToVariable("b");
            Thread.sleep(1000);
            dsm.subscribeToVariable("c");
            Thread.sleep(1000);

            dsm.compareAndExchange("a", 1, 100);
            Thread.sleep(1000);
            dsm.compareAndExchange("c", 3, 300);
            Thread.sleep(1000);
            dsm.compareAndExchange("b", 200, 20);
            Thread.sleep(1000);

            dsm.close();
            Thread.sleep(1000);

            thread.join();
        } else if (rank == 1) {
            Thread thread = new Thread(new Subscriber(dsm));
            thread.start();

            dsm.subscribeToVariable("a");
            Thread.sleep(1000);
            dsm.subscribeToVariable("c");
            Thread.sleep(1000);

            dsm.compareAndExchange("b", 2, 1000);
            Thread.sleep(1000);

            thread.join();
        } else if (rank == 2) {
            Thread thread = new Thread(new Subscriber(dsm));
            thread.start();

            dsm.subscribeToVariable("b");
            Thread.sleep(1000);
            dsm.compareAndExchange("b", 2, 500);
            Thread.sleep(1000);

            thread.join();
        }

        MPI.Finalize();
    }
}