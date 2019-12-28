import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static class UnionFind {
        Map<Integer, Integer> parents;
        Map<Integer, Integer> sizes;
        int max;
        public UnionFind() {
            parents = new HashMap<>();
            sizes = new HashMap<>();
            max = 0;
        }

        public void union(int v1, int v2) {
            if (!parents.containsKey(v1)) {
                parents.put(v1, v1);
                sizes.put(v1, 1);
            }

            if (!parents.containsKey(v2)) {
                parents.put(v2, v2);
                sizes.put(v2, 1);
            }

            int p1 = find(v1), p2 = find(v2);
            if (p1 == p2) return;
            int s1 = sizes.get(p1), s2 = sizes.get(p2);
            if (s1 < s2) {
                parents.put(p1, p2);
                sizes.put(p2, s1 + s2);
                if (s1 + s2 > max) max = s1 + s2;
            }else {
                parents.put(p2, p1);
                sizes.put(p1, s1 + s2);
                if (s1 + s2 > max) max = s1 + s2;
            }
        }

        public int find(int v) {
            while (parents.get(v) != v) {
                parents.put(v, parents.get(parents.get(v)));
                v = parents.get(v);
            }
            return v;
        }
    }

    // Complete the maxCircle function below.
    static int[] maxCircle(int[][] queries) {
        UnionFind uf = new UnionFind();
        int[] res = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            uf.union(queries[i][0], queries[i][1]);
            res[i] = uf.max;
        }
        return res;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[][] queries = new int[q][2];

        for (int i = 0; i < q; i++) {
            String[] queriesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int queriesItem = Integer.parseInt(queriesRowItems[j]);
                queries[i][j] = queriesItem;
            }
        }

        int[] ans = maxCircle(queries);

        for (int i = 0; i < ans.length; i++) {
            bufferedWriter.write(String.valueOf(ans[i]));

            if (i != ans.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
