import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the minimumPasses function below.
static long minimumPasses(long m, long w, long p, long n) {
        long candies = 0;
        long invest = 0;
        long spend = Long.MAX_VALUE;

        while (candies < n) {
                // preventing overflow in m*w
                long passes = (long) (((p - candies) / (double) m) / w);

                if (passes <= 0) {
                        // machines we can buy in total
                        long mw = candies / p + m + w;
                        long half = mw >>> 1;
                        if (m > w) {
                                m = Math.max(m, half);
                                w = mw - m;
                        } else {
                                w = Math.max(w, half);
                                m = mw - w;
                        }
                        candies %= p;
                        passes++;
                }

                // handling overflowing
                // if overflowing is encountered -> candies count are definitely more than long
                // thus it is more than n since n is long
                // so we've reached the goal and we can break the loop
                long mw;
                long pmw;
                try {
                        mw = Math.multiplyExact(m, w);
                        pmw = Math.multiplyExact(passes, mw);
                } catch (ArithmeticException ex) {
                        // we need to add current pass
                        invest += 1;
                        // increment will be 1 because of overflow
                        spend = Math.min(spend, invest + 1);
                        break;
                }

                candies += pmw;
                invest += passes;
                long increment = (long) Math.ceil((n - candies) / (double) mw);
                spend = Math.min(spend, invest + increment);
        }

        return Math.min(spend, invest);
}
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] mwpn = scanner.nextLine().split(" ");

        long m = Long.parseLong(mwpn[0]);

        long w = Long.parseLong(mwpn[1]);

        long p = Long.parseLong(mwpn[2]);

        long n = Long.parseLong(mwpn[3]);

        long result = minimumPasses(m, w, p, n);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
