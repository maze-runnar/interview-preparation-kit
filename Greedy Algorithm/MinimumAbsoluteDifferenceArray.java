import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        for(int a_i=0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
        Arrays.sort(a);
        int min = 2000000000;
        for (int i = 1; i < n; i++) {
            min = Math.min(Math.abs(a[i]-a[i-1]), min);
        }
        System.out.println(min);
    }
}
