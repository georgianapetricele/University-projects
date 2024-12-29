import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.*;

public class HamiltonianCycleParallel {
    private final int[][] graph;

    public HamiltonianCycleParallel(int[][] graph){
        this.graph = graph;
    }

    public static int[][] generateDirectedHamiltonianGraph(int size) {
        int[][] graph = new int[size][size];

        // connect each vertex to the next one
        for (int i = 0; i < size - 1; i++)
            graph[i][i + 1] = 1;

        // connect the last vertex to the first one to form a directed cycle
        graph[size - 1][0] = 1;

        return graph;
    }

    public void findHamiltonianCycle() throws InterruptedException, ExecutionException {
        ArrayList<Integer> path = new ArrayList<>();
        int startingVertex = 0;

        path.add(startingVertex);

        List<Integer> result = findHamiltonianCycle(startingVertex, path);

        if(!result.isEmpty())
            System.out.println("Hamiltonian cycle found: " + result);
        else
            System.out.println("No Hamiltonian cycle found.");
    }

    private List<Integer> findHamiltonianCycle(int currentVertex, ArrayList<Integer> path) throws InterruptedException, ExecutionException {
        // solution found
        if (path.size() == graph.length && graph[currentVertex][path.get(0)] == 1) {
            path.add(path.get(0));
            return path;
        }

        // visited all vertices, but no solution was found
        if (path.size() == graph.length) {
            return new ArrayList<>();
        }

        List<Future<List<Integer>>> futures = new ArrayList<>();

        //up to 8 threads can execute tasks concurrently
        ExecutorService executorService = Executors.newFixedThreadPool(8);
        for (int i = 0; i < graph.length; i++) {
            // if there is an edge between the current vertex and that vertex
            // and the vertex is not already in the path
            if (graph[currentVertex][i] == 1 && !path.contains(i)) {
                ArrayList<Integer> newPath = new ArrayList<>(path);
                newPath.add(i);

                final int vertex = i;
                // for each potential next vertex a new task is created
                Callable<List<Integer>> task = () -> findHamiltonianCycle(vertex, newPath);
                //This allows multiple threads to work on different branches of the search tree concurrently
                futures.add(executorService.submit(task));
            }
        }

        executorService.shutdown();
        executorService.awaitTermination(10, TimeUnit.SECONDS);

        // check the futures list for non-empty results
        for (Future<List<Integer>> future : futures) {
            //waits for each thread's result
            List<Integer> result = future.get();
            if (!result.isEmpty())
                return result;
        }

        return new ArrayList<>();
    }

    public static void displayEdges(int[][] graph){
        for(int i = 0; i < graph.length; i++)
            for(int j = 0; j < graph.length; j++)
                if(graph[i][j] == 1){
                    System.out.println("Edge: " + i + " " + j);
                }
    }

    public static void main(String[] args) throws Exception {
        int[][] graph1 = {
                {0, 1, 0, 1, 0,0},
                {1, 0, 1, 1, 1,0},
                {0, 1, 0, 0, 1,0},
                {1, 1, 0, 0, 1,0},
                {0, 1, 1, 1, 0,0},
                {0,0,0,0,1,0}
        };

        HamiltonianCycleParallel hamiltonianCycleParallel1 = new HamiltonianCycleParallel(graph1);
        double startTime, endTime;
        startTime = System.nanoTime();
        hamiltonianCycleParallel1.findHamiltonianCycle();
        endTime = System.nanoTime();
        System.out.println("Duration: " + (endTime - startTime) / 1_000_000_000.0 + " seconds\n");

        int[][] graph2 = {
                {0, 1, 0, 1, 0},
                {1, 0, 1, 1, 1},
                {0, 1, 0, 0, 1},
                {1, 1, 0, 0, 0},
                {0, 1, 1, 0, 0}
        };
        displayEdges(graph2);
        HamiltonianCycleParallel hamiltonianCycleParallel2 = new HamiltonianCycleParallel(graph2);
        startTime = System.nanoTime();
        hamiltonianCycleParallel2.findHamiltonianCycle();
        endTime = System.nanoTime();
        System.out.println("Duration: " + (endTime - startTime) / 1_000_000_000.0 + " seconds\n");

        int graphSize = 20000;
        int[][] graph3 = generateDirectedHamiltonianGraph(graphSize);
        System.out.println("Graph with " + graphSize + " vertices generated.");
        HamiltonianCycleParallel hamiltonianCycleParallel3 = new HamiltonianCycleParallel(graph3);
        startTime = System.nanoTime();
        hamiltonianCycleParallel3.findHamiltonianCycle();
        endTime = System.nanoTime();
        System.out.println("Duration: " + (endTime - startTime) / 1_000_000_000.0 + " seconds\n");
    }


}