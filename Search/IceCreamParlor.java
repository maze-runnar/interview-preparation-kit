import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class IceCream implements Comparable{
    int flavor;
    int index;

    public IceCream(int flavor, int index) {
      this.flavor = flavor;
        this.index = index;
    }

    @Override
    public int compareTo(Object o) {
       IceCream o2 = (IceCream) o;

       if(this.flavor != o2.flavor)
           return this.flavor - o2.flavor;

       return this.index - o2.index;
    }

    @Override
    public boolean equals(Object o) {
       if(o == null)
           return false;

        if(o == this)
            return true;

        IceCream ice = (IceCream) o;
        return this.flavor == ice.flavor && this.index == ice.index;
    }

    public String toString() {
        return this.flavor + " " + this.index + ";";
    }

}

public class Solution {

    public static int binarySearch(int first, int last, IceCream[] arr, int search) {
        //System.out.println(Arrays.toString(arr));

        while(first <= last) {

            int mid = first + (last-first)/2;
            //System.out.printf("Debug: %d %d\n", mid, search);

            int flavor = arr[mid].flavor;
            if(flavor == search)
                return arr[mid].index;

            if(flavor > search) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }

        //System.out.printf("Debug: -1 %d\n", search);

        return -1;

    }

    public static void main(String[] args) {

        int t;
        int n, m;

        Scanner in = new Scanner(System.in);
        t = in.nextInt();
       for(int test = 0; test < t; test++) {

            m = in.nextInt();
            n = in.nextInt();
            IceCream[] arr = new IceCream[n];

            for (int i = 0; i < n; i++) {
                arr[i] = new IceCream(in.nextInt(), i + 1);
            }

          // System.out.println(Arrays.toString(arr));


            Arrays.sort(arr);
          // System.out.println(Arrays.toString(arr));

            int firstIndex = 100000, secondIndex = 100000;
            for(int i = 0; i < n - 1 ; i++) {
                int search = m - arr[i].flavor;
                if(search >= arr[i].flavor) {
                    int index = binarySearch( i + 1, n - 1, arr, search);
                    if( index != -1 ) {
                        System.out.println( Math.min(arr[i].index, index) + " " + Math.max(arr[i].index, index));
                        break;

                    }
                }
            }

        }

    }

}
