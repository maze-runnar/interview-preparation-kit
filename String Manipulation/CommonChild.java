import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) throws Exception {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
         BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    String s=br.readLine();
    String s2=br.readLine();
    int M = s.length();
    int N = s2.length();

             int[][] arr = new int[M+1][N+1];
        for (int i = M-1; i >= 0; i--) {
            for (int j = N-1; j >= 0; j--) {
                if (s.charAt(i) == s2.charAt(j))
                    arr[i][j] = arr[i+1][j+1] + 1;
                else 
                    arr[i][j] = Math.max(arr[i+1][j], arr[i][j+1]);
            }
        }
        int i = 0, j = 0;
        int count =0;
        while(i < M && j < N) {
            if (s.charAt(i) == s2.charAt(j)) {
                count++;
                i++;
                j++;
            }
            else if (arr[i+1][j] >= arr[i][j+1]) i++;
            else                                 j++;
        }
        System.out.println(count);
    }
}
