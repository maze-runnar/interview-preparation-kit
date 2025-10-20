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

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    // Approach 1: Two Pointers (when elements to remove are rare)
    int removeElementTwoPointers(std::vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
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
    int removeElement(std::vector<int>& nums, int val) {
        int i = 0; // Slow pointer, indicates the position to place the next non-val element
        for (int j = 0; j < nums.size(); ++j) { // Fast pointer, iterates through the array
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main() {
    Solution sol;

    std::cout << "Testing Remove Element (Two Pointers - frequent):\n";

    // Test 1
    std::vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int k1 = sol.removeElement(nums1, val1);
    std::cout << "Input: nums = [3,2,2,3], val = 3 -> Output: " << k1 << ", nums = [";
    for (int i = 0; i < k1; ++i) {
        std::cout << nums1[i];
        if (i < k1 - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: 2, nums = [2,2])\n";

    // Test 2
    std::vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int k2 = sol.removeElement(nums2, val2);
    std::cout << "Input: nums = [0,1,2,2,3,0,4,2], val = 2 -> Output: " << k2 << ", nums = [";
    for (int i = 0; i < k2; ++i) {
        std::cout << nums2[i];
        if (i < k2 - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: 5, nums = [0,1,4,0,3])\n";

    // Test 3
    std::vector<int> nums3 = {};
    int val3 = 0;
    int k3 = sol.removeElement(nums3, val3);
    std::cout << "Input: nums = [], val = 0 -> Output: " << k3 << ", nums = [";
    for (int i = 0; i < k3; ++i) {
        std::cout << nums3[i];
        if (i < k3 - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: 0, nums = [])\n";

    // Test 4
    std::vector<int> nums4 = {1};
    int val4 = 1;
    int k4 = sol.removeElement(nums4, val4);
    std::cout << "Input: nums = [1], val = 1 -> Output: " << k4 << ", nums = [";
    for (int i = 0; i < k4; ++i) {
        std::cout << nums4[i];
        if (i < k4 - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: 0, nums = [])\n";

    std::cout << "\nTesting Remove Element (Two Pointers - rare):\n";

    // Test 5
    std::vector<int> nums5 = {3, 2, 2, 3};
    int val5 = 3;
    int k5 = sol.removeElementTwoPointers(nums5, val5);
    std::cout << "Input: nums = [3,2,2,3], val = 3 -> Output: " << k5 << ", nums = [";
    for (int i = 0; i < k5; ++i) {
        std::cout << nums5[i];
        if (i < k5 - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: 2, nums = [2,2])\n";

    // Test 6
    std::vector<int> nums6 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val6 = 2;
    int k6 = sol.removeElementTwoPointers(nums6, val6);
    std::cout << "Input: nums = [0,1,2,2,3,0,4,2], val = 2 -> Output: " << k6 << ", nums = [";
    for (int i = 0; i < k6; ++i) {
        std::cout << nums6[i];
        if (i < k6 - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: 5, nums = [0,1,4,0,3] or similar)\n";

    return 0;
}
