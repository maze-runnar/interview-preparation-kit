import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner s = new Scanner(System.in);
        /*long n0 = s.nextLong();
        long n1 = s.nextLong();
        long n = 9L;
        if(((n0%n)*(n1%n))%n==0)
            System.out.println(n);
        else
            System.out.println(((n0%n)*(n1%n))%n);*/
        String f = s.next();
        int n1 = s.nextInt();
        int n0=0;
        char[] c = f.toCharArray();
        for(char i:c){
            n0+=Character.getNumericValue(i);
            n0%=9;
        }
        int n = 9;
        if(((n0%n)*(n1%n))%n==0)
            System.out.println(n);
        else
            System.out.println(((n0%n)*(n1%n))%n);

    }

}
