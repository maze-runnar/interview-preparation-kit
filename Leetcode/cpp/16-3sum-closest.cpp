/*
Problem 16: 3Sum Closest
https://leetcode.com/problems/3sum-closest/

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Constraints:
- 3 <= nums.length <= 1000
- -1000 <= nums[i] <= 1000
- -10^4 <= target <= 10^4
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <climits> // For INT_MAX

class Solution {
public:
    // Approach: Two Pointers with Sorting
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2]; // Initialize with the sum of first three elements

        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];

                if (std::abs(target - current_sum) < std::abs(target - closest_sum)) {
                    closest_sum = current_sum;
                }

                if (current_sum < target) {
                    left++;
                } else if (current_sum > target) {
                    right--;
                } else { // current_sum == target, perfect match
                    return target;
                }
            }
        }

        return closest_sum;
    }
};

int main() {
    Solution sol;

    std::cout << "Testing 3Sum Closest:\n";

    std::vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    std::cout << "Input: nums = [-1,2,1,-4], target = 1 -> Output: " << sol.threeSumClosest(nums1, target1) << " (Expected: 2)\n";

    std::vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    std::cout << "Input: nums = [0,0,0], target = 1 -> Output: " << sol.threeSumClosest(nums2, target2) << " (Expected: 0)\n";

    std::vector<int> nums3 = {1, 1, -1, -1, 3};
    int target3 = -1;
    std::cout << "Input: nums = [1,1,-1,-1,3], target = -1 -> Output: " << sol.threeSumClosest(nums3, target3) << " (Expected: -1)\n";

    std::vector<int> nums4 = {1, 1, -1, -4};
    int target4 = 1;
    std::cout << "Input: nums = [1,1,-1,-4], target = 1 -> Output: " << sol.threeSumClosest(nums4, target4) << " (Expected: 2)\n";

    return 0;
}
