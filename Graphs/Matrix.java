import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.List;
//import java.util.Queue;

class WeightedEdge {
    int v, w;

    public WeightedEdge(int v, int w) {
        this.v = v;
        this.w = w;
    }
}

public class Matrix {
    static InputStream is;
    static PrintWriter out;
    static String INPUT = "";
    static List<List<WeightedEdge>> adjList;
    static boolean[] machine;
    static long[][] dp;

    static void dfs(int u, int parent) {
        dp[u][1] = 0;
        dp[u][0] = machine[u] ? Integer.MAX_VALUE : 0;
        List<WeightedEdge> wList = adjList.get(u);
        for (WeightedEdge we : wList) {

            int v = we.v, w = we.w;
            if (v != parent) {
                dfs(v, u);
                dp[u][1] += Math.min(dp[v][0], dp[v][1] + w);
                dp[u][1] = Math.min(dp[u][1], dp[u][0] + dp[v][1]);
                if (!machine[u])
                    dp[u][0] += Math.min(dp[v][0], dp[v][1] + w);
            }
        }
    }

    static void solve() {

        int n = ni(), k = ni();
        int u, v, w;
        adjList = new ArrayList<List<WeightedEdge>>(n);
        for (int i = 0; i < n; i++) {
            adjList.add(new LinkedList<WeightedEdge>());
        }

        for (int i = 0; i < n - 1; i++) {
            u = ni();
            v = ni();
            w = ni();
            adjList.get(u).add(new WeightedEdge(v, w));
            adjList.get(v).add(new WeightedEdge(u, w));
        }

        machine = new boolean[n];
        for (int i = 0; i < k; i++) {
            machine[ni()] = true;
        }

        dp = new long[n][2];

        dfs(0, -1);
//        for(int i=0;i<n;i++){
//            System.out.println(Arrays.toString(dp[i]));
//        }
        out.println(Math.min(dp[0][0], dp[0][1]));
    }

    public static void main(String[] args) throws Exception {
        long S = System.currentTimeMillis();
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(
                INPUT.getBytes());
        out = new PrintWriter(System.out);

        solve();
        out.flush();
        long G = System.currentTimeMillis();
        tr(G - S + "ms");
    }

    private static boolean eof() {
        if (lenbuf == -1)
            return true;
        int lptr = ptrbuf;
        while (lptr < lenbuf)
            if (!isSpaceChar(inbuf[lptr++]))
                return false;

        try {
            is.mark(1000);
            while (true) {
                int b = is.read();
                if (b == -1) {
                    is.reset();
                    return true;
                } else if (!isSpaceChar(b)) {
                    is.reset();
                    return false;
                }
            }
        } catch (IOException e) {
            return true;
        }
    }

    private static byte[] inbuf = new byte[1024];
    static int lenbuf = 0, ptrbuf = 0;

    private static int readByte() {
        if (lenbuf == -1)
            throw new InputMismatchException();
        if (ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try {
                lenbuf = is.read(inbuf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (lenbuf <= 0)
                return -1;
        }
        return inbuf[ptrbuf++];
    }

    private static boolean isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    private static int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b))
            ;
        return b;
    }

    private static double nd() {
        return Double.parseDouble(ns());
    }

    private static char nc() {
        return (char) skip();
    }

    private static String ns() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b !=
                                    // ' ')
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private static char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while (p < n && !(isSpaceChar(b))) {
            buf[p++] = (char) b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private static char[][] nm(int n, int m) {
        char[][] map = new char[n][];
        for (int i = 0; i < n; i++)
            map[i] = ns(m);
        return map;
    }

    private static int[] na(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = ni();
        return a;
    }

    private static int ni() {
        int num = 0, b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
            ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }

        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private static long nl() {
        long num = 0;
        int b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
            ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }

        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private static void tr(Object... o) {
        if (INPUT.length() != 0)
            System.out.println(Arrays.deepToString(o));
    }
}
