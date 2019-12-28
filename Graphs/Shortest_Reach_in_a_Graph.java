import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static class Graph {

        private List<List<Integer>> adjList;
        int V;

        public Graph(int size) {
            this.V = size;
            adjList = new ArrayList();
            for(int i=0; i < V; i++) adjList.add(new ArrayList());
        }

        public void addEdge(int first, int second) {
            adjList.get(first).add(second);
            adjList.get(second).add(first);
        }

        public int[] shortestReach(int startId) { // 0 indexed

            boolean[] marked = new boolean[V];
            int[] distTo = new int[V];
            Arrays.fill(distTo, -1);

            Deque<Integer> queue = new ArrayDeque();
            queue.add(startId);
            marked[startId] = true;
            distTo[startId] = 0;

            while(!queue.isEmpty()){
                int v = queue.poll();
                for(int w : adjList.get(v)){
                    if(!marked[w]){
                        marked[w] = true;
                        distTo[w] = distTo[v] + 6;
                        queue.add(w);
                    }
                }
            }

            return distTo;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int queries = scanner.nextInt();

        for (int t = 0; t < queries; t++) {

            // Create a graph of size n where each edge weight is 6:
            Graph graph = new Graph(scanner.nextInt());
            int m = scanner.nextInt();

            // read and set edges
            for (int i = 0; i < m; i++) {
                int u = scanner.nextInt() - 1;
                int v = scanner.nextInt() - 1;

                // add each edge to the graph
                graph.addEdge(u, v);
            }

            // Find shortest reach from node s
            int startId = scanner.nextInt() - 1;
            int[] distances = graph.shortestReach(startId);

            for (int i = 0; i < distances.length; i++) {
                if (i != startId) {
                    System.out.print(distances[i]);
                    System.out.print(" ");
                }
            }
            System.out.println();
        }

        scanner.close();
    }
}
