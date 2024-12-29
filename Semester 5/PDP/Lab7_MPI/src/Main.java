
import mpi.MPI;
/*
In a shared-memory system, all threads (smaller parts of a program) can access the same memory space. This means:

They don’t need to communicate with each other over a network or send data back and forth.
They can directly read and write from the same place in memory, making things faster.
But in MPI:

The processes (even on the same machine) don’t share memory directly. They have separate memory spaces and need to send data between them.
This sending and receiving takes time, especially if the data is large
 */

public class Main {

    private static final String MULTIPLICATION = "Karatsuba";
    private static final int POLYNOMIAL_ORDER = 10000;

    private static void multiplicationMaster(Polynomial p, Polynomial q, int nrProcs, String type) {
        long startTime = System.currentTimeMillis();
        // indexes of each chunk
        int start = 0, finish = 0;
        //split the coef into nrProcs parts
        int len = p.getLength() / (nrProcs - 1);

        for (int i = 1; i < nrProcs; i++) {
            start = finish;
            finish += len;
            if (i == nrProcs - 1) {
                finish = p.getLength();
            }
            // send(buffer,where to start,how many elements,datatype,destination process,tag)
            //send the polynomials to current worker i
            //wrap the polynomial in array format
            MPI.COMM_WORLD.Send(new Object[]{p}, 0, 1, MPI.OBJECT, i, 0);
            MPI.COMM_WORLD.Send(new Object[]{q}, 0, 1, MPI.OBJECT, i, 0);

            //send the indexes of the chunk the worker is responsible for
            MPI.COMM_WORLD.Send(new int[]{start}, 0, 1, MPI.INT, i, 0);
            MPI.COMM_WORLD.Send(new int[]{finish}, 0, 1, MPI.INT, i, 0);

        }

        // receive the partial results from the workers
        Object[] results = new Object[nrProcs - 1];
        for (int i = 1; i < nrProcs; i++) {
            // receive(buffer,where to start,how many elements,datatype,source process,tag)
            // take offset i-1 because array starts from 0
            MPI.COMM_WORLD.Recv(results, i - 1, 1, MPI.OBJECT, i, 0);
        }


        Polynomial result = Operation.buildResult(results);
        long endTime = System.currentTimeMillis();
        //System.out.println(type + " multiplication of polynomials:\n" + result.toString());
        System.out.println("Execution time: " + (endTime - startTime) + " ms");
    }

    private static void multiplySimpleWorker(int me) {
        System.out.printf("Worker %d started\n", me);

        Object[] p = new Object[2];
        Object[] q = new Object[2];
        int[] begin = new int[1];
        int[] end = new int[1];


        //recv the data from the master
        MPI.COMM_WORLD.Recv(p, 0, 1, MPI.OBJECT, 0, 0);
        MPI.COMM_WORLD.Recv(q, 0, 1, MPI.OBJECT, 0, 0);

        MPI.COMM_WORLD.Recv(begin, 0, 1, MPI.INT, 0, 0);
        MPI.COMM_WORLD.Recv(end, 0, 1, MPI.INT, 0, 0);

        Polynomial result = Operation.multiplySimple(p[0], q[0], begin[0], end[0]);

        // send res back to the master
        MPI.COMM_WORLD.Send(new Object[]{result}, 0, 1, MPI.OBJECT, 0, 0);

    }

    private static void multiplyKaratsubaWorker(int me) {
        System.out.printf("Worker %d started\n", me);

        Object[] p = new Object[2];
        Object[] q = new Object[2];
        int[] begin = new int[1];
        int[] end = new int[1];

        MPI.COMM_WORLD.Recv(p, 0, 1, MPI.OBJECT, 0, 0);
        MPI.COMM_WORLD.Recv(q, 0, 1, MPI.OBJECT, 0, 0);

        MPI.COMM_WORLD.Recv(begin, 0, 1, MPI.INT, 0, 0);
        MPI.COMM_WORLD.Recv(end, 0, 1, MPI.INT, 0, 0);

        //make cast to Polynomial
        Polynomial pp = (Polynomial) p[0];
        Polynomial qq = (Polynomial) q[0];

        // Zero out the coefficients that are outside the range the worker is responsible for
        for (int i = 0; i < begin[0]; i++) {
            pp.getCoefficients().set(i, 0);
        }
        for (int j = end[0]; j < pp.getCoefficients().size(); j++) {
            pp.getCoefficients().set(j, 0);

        }

        Polynomial result = Operation.karatsubaSequential(pp, qq);

        MPI.COMM_WORLD.Send(new Object[]{result}, 0, 1, MPI.OBJECT, 0, 0);
    }

    public static void main(String[] args) {
        // Initialize the MPI environment
        MPI.Init(args);
        int me = MPI.COMM_WORLD.Rank(); //take the id of the process
        int nrProcs = MPI.COMM_WORLD.Size(); //take the number of processes
        if (me == 0) {
            // master process
            System.out.println("Master process generating polynomials:");
            Polynomial p = new Polynomial(POLYNOMIAL_ORDER);
            Polynomial q = new Polynomial(POLYNOMIAL_ORDER);

            System.out.println(p);
            System.out.println(q);

            // split the work between processes
            multiplicationMaster(p, q, nrProcs, MULTIPLICATION);
        } else {
            if ("Karatsuba".compareTo(MULTIPLICATION) == 0){
                multiplyKaratsubaWorker(me);
            }
            else{
                multiplySimpleWorker(me);
            }
        }
        MPI.Finalize();
    }


}