import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

public static void main(String[] args) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int[] a = new int[n];
int[] c = new int[n];
for(int i=0;i<n;i++){
    a[i] = sc.nextInt();
}
    c[0] = 1;
for(int i=1;i<n;i++){
    if(a[i]>a[i-1])
        c[i] = c[i-1]+1;
    else
        c[i] = 1;
}
   for(int i=n-2;i>=0;i--){
    if(a[i]>a[i+1])
        c[i] = Math.max(c[i],c[i+1]+1);
     }
    long sum=0;
    for(int x:c){
        sum+=x;
    }
    System.out.println(sum);
}
}
