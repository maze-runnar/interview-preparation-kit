import java.io.*;
import java.util.*;

public class Solution {

    public static int solution(int[] height) {

    int n = height.length;
    if(n == 0) return 0;

    Stack<Integer> left = new Stack<Integer>();
    Stack<Integer> right = new Stack<Integer>();

    int[] width = new int[n];// widths of intervals.
    Arrays.fill(width, 1);// all intervals should at least be 1 unit wide.

    for(int i = 0; i < n; i++){
        // count # of consecutive higher bars on the left of the (i+1)th bar
        while(!left.isEmpty() && height[i] <= height[left.peek()]){
            // while there are bars stored in the stack, we check the bar on the top of the stack.
            left.pop();
        }

        if(left.isEmpty()){
            // all elements on the left are larger than height[i].
            width[i] += i;
        } else {
            // bar[left.peek()] is the closest shorter bar.
            width[i] += i - left.peek() - 1;
        }
        left.push(i);
    }

    for (int i = n-1; i >=0; i--) {

        while(!right.isEmpty() && height[i] <= height[right.peek()]){
            right.pop();
        }

        if(right.isEmpty()){
            // all elements to the right are larger than height[i]
            width[i] += n - 1 - i;
        } else {
            width[i] += right.peek() - i - 1;
        }
        right.push(i);
    }

    int max = Integer.MIN_VALUE;
    for(int i = 0; i < n; i++){
        // find the maximum value of all rectangle areas.
        max = Math.max(max, width[i] * height[i]);
    }

    return max;
}

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int height[] = new int[n];
        for (int i = 0; i < n; i++)
            height[i] = in.nextInt();
        System.out.println(solution(height));
    }
}
