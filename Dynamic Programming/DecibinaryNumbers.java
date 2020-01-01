import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Solution {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DecibinaryNumbers solver = new DecibinaryNumbers();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class DecibinaryNumbers {
        public static final int N = 20;
        long[][] qty = new long[1 << N][N];
        long[] cumulative = new long[1 << N];

        {
            qty[0][0] = 1;
            for (int i = 1; i <= N - 1; i++) {
                for (int j = 0; j < (1 << N); j++) {
                    if (qty[j][i - 1] == 0) {
                        continue;
                    }
                    for (int k = 0; k < 10; k++) {
                        int value = (k << (i - 1)) + j;
                        if (value >= (1 << N)) {
                            break;
                        }
                        qty[value][i] += qty[j][i - 1];
                    }
                }
            }
            cumulative[0] = 1;
            for (int i = 1; i < (1 << N); i++) {
                cumulative[i] = cumulative[i - 1] + qty[i][N - 1];
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long x = in.readLong() - 1;
            if (x == 0) {
                out.printLine(0);
                return;
            }
            int at = Arrays.binarySearch(cumulative, x);
            if (at < 0) {
                at = -at - 2;
            }
            x -= cumulative[at];
            at++;
            StringBuilder answer = new StringBuilder();
            for (int i = N - 1; i > 0; i--) {
                for (int j = 0; j < 10; j++) {
                    if (qty[at - (j << (i - 1))][i - 1] <= x) {
                        x -= qty[at - (j << (i - 1))][i - 1];
                    } else {
                        at -= (j << (i - 1));
                        if (j > 0 || answer.length() > 0) {
                            answer.append(j);
                        }
                        break;
                    }
                }
            }
            out.printLine(answer);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public long readLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }
}
