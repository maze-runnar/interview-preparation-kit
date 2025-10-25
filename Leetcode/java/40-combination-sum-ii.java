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

import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> combination = new ArrayList<>();
        
        // Sort to handle duplicates and enable early termination
        Arrays.sort(candidates);
        
        backtrack(candidates, target, 0, combination, result);
        return result;
    }
    
    private void backtrack(int[] candidates, int target, int start, 
                          List<Integer> combination, List<List<Integer>> result) {
        if (target == 0) {
            result.add(new ArrayList<>(combination));
            return;
        }
        
        for (int i = start; i < candidates.length; i++) {
            // Skip duplicates: if current element is same as previous and we haven't used previous
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            // Early termination if current candidate exceeds target
            if (candidates[i] > target) break;
            
            combination.add(candidates[i]);
            // Use i + 1 to avoid reusing same element (each number used only once)
            backtrack(candidates, target - candidates[i], i + 1, combination, result);
            combination.remove(combination.size() - 1); // backtrack
        }
    }
}
