import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    private static long mergeSort(int[] array) {
        int[] aux = new int[array.length];
        for (int i = 0; i < array.length; i++) {
            aux[i] = array[i];
        }
        return sort(array, 0, array.length - 1, aux);
    }

    private static long sort(int[] array, int left, int right, int[] aux) {
        if (left >= right) {
            return 0;
        }
        int mid = (left + right) / 2;
        long a = sort(aux, left, mid, array);
        long b = sort(aux, mid + 1, right, array);
        long c = merge(array, left, mid, right, aux);
        return a + b + c;
    }

    private static long merge(int[] array, int left, int mid, int right,
                              int[] aux) {
        int idx = left;
        int left1 = left;
        int right1 = mid;
        int left2 = mid + 1;
        int right2 = right;
        long count = 0;
        while (left1 <= right1 && left2 <= right2) {
            if (aux[left1] <= aux[left2]) {
                array[idx++] = aux[left1];
                left1++;
            } else {
                array[idx++] = aux[left2];
                count += (mid - left1 + 1);
                left2++;
            }
        }
        while (left1 <= right1) {
            array[idx++] = aux[left1];
            left1++;
        }
        while (left2 <= right2) {
            array[idx++] = aux[left2];
            left2++;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int a0 = 0; a0 < t; a0++) {
            int n = in.nextInt();
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextInt();
            }
            System.out.println(mergeSort(arr));
        }
    }
}
