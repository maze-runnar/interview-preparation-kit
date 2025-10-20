/*
Problem 11: Container With Most Water
https://leetcode.com/problems/container-with-most-water/

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Constraints:
- n == height.length
- 2 <= n <= 10^5
- 0 <= height[i] <= 10^4
*/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    // Approach: Two Pointers
    int maxArea(std::vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int current_height = std::min(height[left], height[right]);
            int current_width = right - left;
            max_area = std::max(max_area, current_height * current_width);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};

int main() {
    Solution sol;

    std::cout << "Testing Container With Most Water:\n";

    std::vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << "Input: [1,8,6,2,5,4,8,3,7] -> Output: " << sol.maxArea(h1) << " (Expected: 49)\n";

    std::vector<int> h2 = {1, 1};
    std::cout << "Input: [1,1] -> Output: " << sol.maxArea(h2) << " (Expected: 1)\n";

    std::vector<int> h3 = {4, 3, 2, 1, 4};
    std::cout << "Input: [4,3,2,1,4] -> Output: " << sol.maxArea(h3) << " (Expected: 16)\n";

    std::vector<int> h4 = {1, 2, 1};
    std::cout << "Input: [1,2,1] -> Output: " << sol.maxArea(h4) << " (Expected: 2)\n";

    return 0;
}
