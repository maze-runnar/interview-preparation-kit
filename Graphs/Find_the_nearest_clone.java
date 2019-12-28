import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static int findShortest(int graphNodes, int[] graphFrom, int[] graphTo, int[] ids, int val) {
        LinkedList<Integer>[] map = new LinkedList[graphNodes];
        HashMap<Integer, Integer> distances = new HashMap();

        for(int i = 0 ; i < graphNodes; i++){
            map[i] = new LinkedList<Integer>();
        }

        for(int i = 0; i < graphFrom.length; i++){
            map[graphFrom[i] - 1].add(graphTo[i]);
            map[graphTo[i] - 1].add(graphFrom[i]);
        }

        Queue<Integer> queue = new LinkedList();
        for(int i = 0; i < ids.length; i++){
            if(ids[i] == val){
                queue.add(i + 1);
                distances.put(i + 1, 0);
            }
        }

        if(queue.size() < 2){
            return -1;
        }
        HashSet<Integer> seen = new HashSet();
        while(queue.size() > 0){
            int current = queue.poll();
            seen.add(current);

            for(int a : map[current - 1]){
                if(distances.containsKey(a) && !seen.contains(a)){
                    return distances.get(a) + distances.get(current) + 1;
                }
                else {
                    queue.add(a);
                    distances.put(a, distances.get(current) + 1);
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] graphNodesEdges = br.readLine().split(" ");
        int graphNodes = Integer.parseInt(graphNodesEdges[0].trim());
        int graphEdges = Integer.parseInt(graphNodesEdges[1].trim());

        int[] graphFrom = new int[graphEdges];
        int[] graphTo = new int[graphEdges];

        for (int i = 0; i < graphEdges; i++) {
            String[] graphFromTo = br.readLine().split(" ");
            graphFrom[i] = Integer.parseInt(graphFromTo[0].trim());
            graphTo[i] = Integer.parseInt(graphFromTo[1].trim());
        }

        int[] ids = new int[graphNodes];

        String[] idsItems = br.readLine().split(" ");

        for (int i = 0; i < graphNodes; i++) {
            int idsItem = Integer.parseInt(idsItems[i]);
            ids[i] = idsItem;
        }

        int val = Integer.parseInt(br.readLine().split(" ")[0]);
        br.close();

        int ans = findShortest(graphNodes, graphFrom, graphTo, ids, val);

        bufferedWriter.write(String.valueOf(ans));
        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
