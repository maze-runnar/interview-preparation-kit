/*
Problem 27: Remove Element
https://leetcode.com/problems/remove-element/

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val to be k. To be accepted, you need to return k, and the first k elements of nums should contain the elements which are not equal to val. The remaining elements of nums beyond the first k elements and their size are not important.

Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2. It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 1, 4, 0, and 3 in some order. It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:
- 0 <= nums.length <= 100
- 0 <= nums[i] <= 50
- 0 <= val <= 100
*/

import java.util.Arrays;

class Solution {
    // Approach 1: Two Pointers (when elements to remove are rare)
    public int removeElementTwoPointers(int[] nums, int val) {
        int i = 0;
        int n = nums.length;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1]; // Move the last element to the current position
                // Reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }

    // Approach 2: Two Pointers (when elements to remove are frequent)
    public int removeElement(int[] nums, int val) {
        int i = 0; // Slow pointer, indicates the position to place the next non-val element
        for (int j = 0; j < nums.length; j++) { // Fast pointer, iterates through the array
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Remove Element (Two Pointers - frequent):\n");

        // Test 1
        int[] nums1 = {3, 2, 2, 3};
        int val1 = 3;
        int k1 = sol.removeElement(nums1, val1);
        System.out.println("Input: nums = [3,2,2,3], val = 3 -> Output: " + k1 + ", nums = " + Arrays.toString(Arrays.copyOfRange(nums1, 0, k1)) + " (Expected: 2, nums = [2,2])");

        // Test 2
        int[] nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
        int val2 = 2;
        int k2 = sol.removeElement(nums2, val2);
        System.out.println("Input: nums = [0,1,2,2,3,0,4,2], val = 2 -> Output: " + k2 + ", nums = " + Arrays.toString(Arrays.copyOfRange(nums2, 0, k2)) + " (Expected: 5, nums = [0,1,4,0,3] or similar)");

        // Test 3
        int[] nums3 = {};
        int val3 = 0;
        int k3 = sol.removeElement(nums3, val3);
        System.out.println("Input: nums = [], val = 0 -> Output: " + k3 + ", nums = " + Arrays.toString(Arrays.copyOfRange(nums3, 0, k3)) + " (Expected: 0, nums = [])");

        // Test 4
        int[] nums4 = {1};
        int val4 = 1;
        int k4 = sol.removeElement(nums4, val4);
        System.out.println("Input: nums = [1], val = 1 -> Output: " + k4 + ", nums = " + Arrays.toString(Arrays.copyOfRange(nums4, 0, k4)) + " (Expected: 0, nums = [])");

        System.out.println("\nTesting Remove Element (Two Pointers - rare):\n");

        // Test 5
        int[] nums5 = {3, 2, 2, 3};
        int val5 = 3;
        int k5 = sol.removeElementTwoPointers(nums5, val5);
        System.out.println("Input: nums = [3,2,2,3], val = 3 -> Output: " + k5 + ", nums = " + Arrays.toString(Arrays.copyOfRange(nums5, 0, k5)) + " (Expected: 2, nums = [2,2])");

        // Test 6
        int[] nums6 = {0, 1, 2, 2, 3, 0, 4, 2};
        int val6 = 2;
        int k6 = sol.removeElementTwoPointers(nums6, val6);
        System.out.println("Input: nums = [0,1,2,2,3,0,4,2], val = 2 -> Output: " + k6 + ", nums = " + Arrays.toString(Arrays.copyOfRange(nums6, 0, k6)) + " (Expected: 5, nums = [0,1,4,0,3] or similar)");
    }
}
