import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static boolean bs(int[]a, int x){
        int lo, hi , mid;
        lo = 0;
        hi = a.length;
        while(hi > lo){
            mid = (hi+lo)/2;
            if(a[mid]>x) hi = mid;
            else if(a[mid]<x) lo = mid+1;
            else return true;
        }
        return false;
    }

    static int pairs(int[] a,int k) {
      /* Complete this function */
        Arrays.sort(a);
        int pairs = 0;
        for(int i =0 ; i < a.length ; i++){
            if(bs(a,a[i]+k)){
                pairs++;
            }
        }
        return pairs;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int res;

        String n = in.nextLine();
        String[] n_split = n.split(" ");

        int _a_size = Integer.parseInt(n_split[0]);
        int _k = Integer.parseInt(n_split[1]);

        int[] _a = new int[_a_size];
        int _a_item;
        String next = in.nextLine();
        String[] next_split = next.split(" ");

        for(int _a_i = 0; _a_i < _a_size; _a_i++) {
            _a_item = Integer.parseInt(next_split[_a_i]);
            _a[_a_i] = _a_item;
        }

        res = pairs(_a,_k);
        System.out.println(res);
    }
}	Pairs
