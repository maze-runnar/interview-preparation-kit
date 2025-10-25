/*
47. Permutations II
Medium - 62.4%

Given a collection of numbers, nums, that might contain duplicates, return all the possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output: [[1,1,2],[1,2,1],[2,1,1]]

Example 2:
Input: nums = [1,2,1,1]
Output: [[1,1,1,2],[1,1,2,1],[1,2,1,1],[2,1,1,1]]

Example 3:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        // Sort to handle duplicates
        sort(nums.begin(), nums.end());
        
        backtrack(nums, current, used, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
        // Base case: if current permutation is complete
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Try each unused number
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            
            // Skip duplicates: if current number is same as previous and previous is not used
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            
            // Choose
            current.push_back(nums[i]);
            used[i] = true;
            
            // Explore
            backtrack(nums, current, used, result);
            
            // Unchoose (backtrack)
            current.pop_back();
            used[i] = false;
        }
    }
};
