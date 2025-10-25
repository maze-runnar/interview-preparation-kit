/*
45. Jump Game II
Medium - 42.0%

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, 
if you are at nums[i], you can jump to any nums[i + j] where:
- 0 <= j <= nums[i]
- i + j < n

Return the minimum number of jumps to reach nums[n - 1].

The test cases are generated such that you can reach nums[n - 1].

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        // We don't need to jump from the last index
        for (int i = 0; i < n - 1; i++) {
            // Update the farthest point we can reach
            farthest = max(farthest, i + nums[i]);
            
            // If we've reached the end of current jump range
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                
                // If we can already reach the end, break
                if (currentEnd >= n - 1) break;
            }
        }
        
        return jumps;
    }
};
