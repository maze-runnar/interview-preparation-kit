import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {

    // leave empty to read from stdin/stdout
    private static final String TASK_NAME_FOR_IO = "";

    // file names
    private static final String FILE_IN = TASK_NAME_FOR_IO + ".in";
    private static final String FILE_OUT = TASK_NAME_FOR_IO + ".out";

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tokenizer = new StringTokenizer("");

    public static void main(String[] args) {
        new Solution().run();
    }

    int n, k;
    long[] a;

    private void solve() throws IOException {
        n = nextInt();
        k = nextInt();
        a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
        }
        Arrays.sort(a);

        long answer = 0;
        int taken = 0;
        for (int i = n - 1; i >= 0; i--) {
            answer += a[i] * (1 + (taken / k));
            taken++;
        }

        out.print(answer);
    }

    public void run() {
        long timeStart = System.currentTimeMillis();

        boolean fileIO = TASK_NAME_FOR_IO.length() > 0;
        try {

            if (fileIO) {
                in = new BufferedReader(new FileReader(FILE_IN));
                out = new PrintWriter(new FileWriter(FILE_OUT));
            } else {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter(new OutputStreamWriter(System.out));
            }

            solve();

            in.close();
            out.close();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
        long timeEnd = System.currentTimeMillis();

        if (fileIO) {
            System.out.println("Time spent: " + (timeEnd - timeStart) + " ms");
        }
    }

    private String nextToken() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private BigInteger nextBigInt() throws IOException {
        return new BigInteger(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

}
