import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        List<Integer> ar = new ArrayList<Integer>();
        int ans = 0;
        for(int i=0; i<n; i++) {
            int val = in.nextInt();
            int imp = in.nextInt();
            if(imp == 0)
                ans += val;
            else
                ar.add(val);
        }
        Collections.sort(ar, Collections.reverseOrder());
        for(int i=0; i<ar.size(); i++) {
            if(i < k)
                ans += ar.get(i);
            else
                ans -= ar.get(i);
        }
        System.out.print(ans);
    }
}
