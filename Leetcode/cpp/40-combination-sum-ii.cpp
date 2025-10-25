/*
40. Combination Sum II
Medium - 58.4%

Given a collection of candidate numbers (candidates) and a target number (target), find all unique 
combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [[1,1,6],[1,2,5],[1,7],[2,6]]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: [[1,2,2],[5]]
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        
        // Sort to handle duplicates and enable early termination
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, combination, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates: if current element is same as previous and we haven't used previous
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            // Early termination if current candidate exceeds target
            if (candidates[i] > target) break;
            
            combination.push_back(candidates[i]);
            // Use i + 1 to avoid reusing same element (each number used only once)
            backtrack(candidates, target - candidates[i], i + 1, combination, result);
            combination.pop_back(); // backtrack
        }
    }
};
