import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static class Point {
    public char key;
    public long count;

    public Point(char x, long y) {
        key = x;
        count = y;
    }
}

    // Complete the substrCount function below.
    static long substrCount(int n, String s) {
            s = s + " ";
    ArrayList<Point> l = new ArrayList<Point>();
    long count = 1;
    char ch = s.charAt(0);
    for(int i = 1; i <= n ; i++) {
        if(ch == s.charAt(i))
            count++;
        else {
            l.add(new Point(ch, count));
            count = 1;
            ch = s.charAt(i);
        }
    }
    count = 0;
    if(l.size() >= 3) {
        Iterator<Point> itr = l.iterator();
        Point prev, curr, next;
        curr = (Point)itr.next();
        next = (Point)itr.next();
        count = (curr.count * (curr.count + 1)) / 2;
        for(int i = 1; i < l.size() - 1; i++) {
            prev = curr;
            curr = next;
            next = itr.next();
            count += (curr.count * (curr.count + 1)) / 2;
            if(prev.key == next.key && curr.count == 1)
                count += prev.count > next.count ? next.count : prev.count;
        }
        count += (next.count * (next.count + 1)) / 2;
    } else {
        for(Point curr:l){
            count += (curr.count * (curr.count + 1)) / 2;
        }
    }
    return count;


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String s = scanner.nextLine();

        long result = substrCount(n, s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
