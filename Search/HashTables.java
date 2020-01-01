import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int m = in.nextInt();
            int n = in.nextInt();
            IceCream[] parlor = new IceCream[n];
            for(int a_i=0; a_i < n; a_i++) {
                parlor[a_i] = new IceCream(a_i + 1, in.nextInt());
            }
            Arrays.sort(parlor); 
            for (int i = 0; i < parlor.length - 1; i++) {
                int j = binarySearch(parlor, i + 1, parlor.length - 1, m - parlor[i].price);
                if (j != -1) {
                    if (parlor[i].id < parlor[j].id) {
                        System.out.println(parlor[i].id + " " + parlor[j].id);
                    } else {
                        System.out.println(parlor[j].id + " " + parlor[i].id);
                    }
                    break;
                }
            }
        }
    }
    
    public static int binarySearch(IceCream[] parlor, int start, int end, int target) {
        int middle = (start + end) / 2;
        if(end < start) {
            return -1;
        }
        if(target == parlor[middle].price) {
            return middle;
        } else if(target < parlor[middle].price) {
            return binarySearch(parlor, start, middle - 1, target);
        } else {
            return binarySearch(parlor, middle + 1, end, target);
        }
    }
}

class IceCream implements Comparable<IceCream> {
    
    Integer id;
    Integer price;
    
    IceCream(int id, int price) {
        this.id = id;
        this.price = price;
    }
    
    @Override
    public int compareTo(IceCream o) {
        return this.price.compareTo(o.price);
    }
}
