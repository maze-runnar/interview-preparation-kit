import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

static class BitTree {
        BitTree one;
        BitTree zero;

        BitTree write(boolean v) {
            if (v) {
                if (one == null) {
                    one = new BitTree();
                }
                return one;
            } else {
                if (zero == null) {
                    zero = new BitTree();
                }
                return zero;
            }
        }
    }

    // Complete the maxXor function below.
    static int[] maxXor(int[] arr, int[] queries) {
        final BitTree tree = new BitTree();
        for (int v : arr) {
            BitTree h = tree;
            for (int b = 0; b < 32; ++b) {
                h = h.write((v & 0x80000000) != 0);
                v = v << 1;
            }
        }

        int result[] = new int[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            int q = queries[i];
            int v = 0;
            BitTree h = tree;
            for (int b = 0; b < 32; ++b) {
                v = v << 1;
                if ((q & 0x80000000) == 0) {
                    // Not inverted. Follow high.
                    if (h.one != null) {
                        h = h.one;
                        v |= 1;
                    } else {
                        h = h.zero;
                    }
                } else {
                    // Inverted. Follow low.
                    if (h.zero != null) {
                        h = h.zero;
                        v |= 1;
                    } else {
                        h = h.one;
                    }
                }
                q= q << 1;
            }
            result[i] = v;
        }

        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] queries = new int[m];

        for (int i = 0; i < m; i++) {
            int queriesItem = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
            queries[i] = queriesItem;
        }

        int[] result = maxXor(arr, queries);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
