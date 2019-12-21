import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
public static void main(String[] args) {
    Scanner sc  = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    int min = 0;
    for(int i=0; i<n; i++){
        a[i] = sc.nextInt();
        if(i == 0)
            min = a[i];
        else{
            if(min>a[i-1])
                min = a[i-1];
        }
    }
    if(min != 1)
        for(int i = 0; i<n;i++){
            a[i] = a[i]-(min-1);
        }

    int count=0;
    int temp=0;
    for(int i=0; i<n;) {
        if(a[i] != i+1){
            temp = a[i];
            a[i]= a[temp-1];
            a[temp-1] = temp;
            count++;
        }
        else
            i++;
    }
    System.out.println(count);
}

}
