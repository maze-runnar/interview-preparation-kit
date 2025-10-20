/*
Problem 18: 4Sum
https://leetcode.com/problems/4sum/

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:
- 1 <= nums.length <= 200
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
*/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    // Approach: Two Pointers with Sorting (Extension of 3Sum)
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 4) {
            return result;
        }

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;
                long long current_target = (long long)target - nums[i] - nums[j]; // Use long long for target to prevent overflow

                while (left < right) {
                    long long current_sum = (long long)nums[left] + nums[right];

                    if (current_sum == current_target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third and fourth elements
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (current_sum < current_target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};

void printResult(const std::vector<std::vector<int>>& result) {
    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j];
            if (j < result[i].size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if (i < result.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]\n";
}

int main() {
    Solution sol;

    std::cout << "Testing 4Sum:\n";

    std::vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    std::cout << "Input: nums = [1,0,-1,0,-2,2], target = 0 -> Output: ";
    printResult(sol.fourSum(nums1, target1));
    std::cout << " (Expected: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]])\n";

    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    std::cout << "Input: nums = [2,2,2,2,2], target = 8 -> Output: ";
    printResult(sol.fourSum(nums2, target2));
    std::cout << " (Expected: [[2,2,2,2]])\n";

    std::vector<int> nums3 = {0, 0, 0, 0};
    int target3 = 0;
    std::cout << "Input: nums = [0,0,0,0], target = 0 -> Output: ";
    printResult(sol.fourSum(nums3, target3));
    std::cout << " (Expected: [[0,0,0,0]])\n";

    std::vector<int> nums4 = {-5,-4,-3,-2,-1,0,0,1,2,3,4,5};
    int target4 = 0;
    std::cout << "Input: nums = [-5,-4,-3,-2,-1,0,0,1,2,3,4,5], target = 0 -> Output: ";
    printResult(sol.fourSum(nums4, target4));
    // Expected: [[-5,-4,4,5],[-5,-3,3,5],[-5,-2,2,5],[-5,-2,3,4],[-5,-1,1,5],[-5,-1,2,4],[-5,0,0,5],[-5,0,1,4],[-5,0,2,3],[-4,-3,2,5],[-4,-3,1,4],[-4,-3,0,3],[-4,-2,1,3],[-4,-2,0,2],[-4,-1,0,1],[-3,-2,0,5],[-3,-2,1,4],[-3,-1,1,3],[-3,-1,0,2],[-3,0,0,3],[-3,0,1,2],[-2,-1,0,3],[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    std::cout << " (Expected: [[-5,-4,4,5],[-5,-3,3,5],[-5,-2,2,5],[-5,-2,3,4],[-5,-1,1,5],[-5,-1,2,4],[-5,0,0,5],[-5,0,1,4],[-5,0,2,3],[-4,-3,2,5],[-4,-3,1,4],[-4,-3,0,3],[-4,-2,1,3],[-4,-2,0,2],[-4,-1,0,1],[-3,-2,0,5],[-3,-2,1,4],[-3,-1,1,3],[-3,-1,0,2],[-3,0,0,3],[-3,0,1,2],[-2,-1,0,3],[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]])\n";

    return 0;
}
