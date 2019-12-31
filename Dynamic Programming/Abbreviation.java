import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        sc.nextLine();
        for (int z = 0; z < q; z++) {
            char[] a = sc.nextLine().toCharArray();
            char[] b = sc.nextLine().toCharArray();
            boolean[][] dp = new boolean[a.length+1][b.length+1];
            for (int i = 0; i <= a.length; i++)
            dp[i][0] = true;
            for (int i = 1; i <= a.length; i++) {
                if (a[i-1]>='A'&&a[i-1]<='Z') {
                    for (int j = 1; j <= b.length; j++) {
                        if (b[j-1]==a[i-1])
                            dp[i][j] = dp[i-1][j-1];
                    }
                } else {
                    char c = (char)(a[i-1]-32);
                    for (int j = 1; j <= b.length; j++) {
                        if (b[j-1]==c)
                            dp[i][j] = dp[i-1][j-1];
                        dp[i][j] |= dp[i-1][j];
                    }
                }
            }
            System.out.println(dp[a.length][b.length]?"YES":"NO");
        }
    }
}
