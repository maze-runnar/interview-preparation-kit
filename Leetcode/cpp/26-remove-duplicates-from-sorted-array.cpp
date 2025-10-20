/*
Problem 26: Remove Duplicates from Sorted Array
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k. To be accepted, you need to return k, and the first k elements of nums should contain the unique elements in the order they were present in nums. The remaining elements of nums beyond the first k elements and their size are not important.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:
- 1 <= nums.length <= 3 * 10^4
- -100 <= nums[i] <= 100
- nums is sorted in non-decreasing order.
*/

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    // Approach: Two Pointers
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int i = 0; // Slow pointer, keeps track of the position for the next unique element
        for (int j = 1; j < nums.size(); ++j) { // Fast pointer, iterates through the array
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

int main() {
    Solution sol;

    std::cout << "Testing Remove Duplicates from Sorted Array:\n";

    // Test 1
    std::vector<int> nums1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(nums1);
    std::cout << "Input: [1,1,2] -> Output: " << k1 << ", nums = [";
    for (int i = 0; i < k1; ++i) {
        std::cout << nums1[i];
        if (i < k1 - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: 2, nums = [1,2,_])\n";

    // Test 2
    std::vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(nums2);
    std::cout << "Input: [0,0,1,1,1,2,2,3,3,4] -> Output: " << k2 << ", nums = [";
    for (int i = 0; i < k2; ++i) {
        std::cout << nums2[i];
        if (i < k2 - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: 5, nums = [0,1,2,3,4,_,_,_,_,_])\n";

    // Test 3
    std::vector<int> nums3 = {1, 1, 1, 1, 1};
    int k3 = sol.removeDuplicates(nums3);
    std::cout << "Input: [1,1,1,1,1] -> Output: " << k3 << ", nums = [";
    for (int i = 0; i < k3; ++i) {
        std::cout << nums3[i];
        if (i < k3 - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: 1, nums = [1])\n";

    // Test 4
    std::vector<int> nums4 = {1, 2, 3, 4, 5};
    int k4 = sol.removeDuplicates(nums4);
    std::cout << "Input: [1,2,3,4,5] -> Output: " << k4 << ", nums = [";
    for (int i = 0; i < k4; ++i) {
        std::cout << nums4[i];
        if (i < k4 - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: 5, nums = [1,2,3,4,5])\n";

    // Test 5
    std::vector<int> nums5 = {};
    int k5 = sol.removeDuplicates(nums5);
    std::cout << "Input: [] -> Output: " << k5 << ", nums = [";
    for (int i = 0; i < k5; ++i) {
        std::cout << nums5[i];
        if (i < k5 - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: 0, nums = [])\n";

    return 0;
}
