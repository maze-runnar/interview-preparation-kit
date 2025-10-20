/*
Problem 15: 3Sum
https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0. 

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
- 3 <= nums.length <= 3000
- -10^5 <= nums[i] <= 10^5
*/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    // Approach: Two Pointers with Sorting
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            // Skip duplicate for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the second and third elements
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
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

    std::cout << "Testing 3Sum:\n";

    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    std::cout << "Input: [-1,0,1,2,-1,-4] -> Output: ";
    printResult(sol.threeSum(nums1));
    std::cout << " (Expected: [[-1,-1,2],[-1,0,1]])\n";

    std::vector<int> nums2 = {0, 1, 1};
    std::cout << "Input: [0,1,1] -> Output: ";
    printResult(sol.threeSum(nums2));
    std::cout << " (Expected: [])\n";

    std::vector<int> nums3 = {0, 0, 0};
    std::cout << "Input: [0,0,0] -> Output: ";
    printResult(sol.threeSum(nums3));
    std::cout << " (Expected: [[0,0,0]])\n";

    std::vector<int> nums4 = {-2, 0, 1, 1, 2};
    std::cout << "Input: [-2,0,1,1,2] -> Output: ";
    printResult(sol.threeSum(nums4));
    std::cout << " (Expected: [[-2,0,2],[-2,1,1]])\n";

    return 0;
}
