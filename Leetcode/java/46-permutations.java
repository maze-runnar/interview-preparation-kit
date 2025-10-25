/*
46. Permutations
Medium - 81.2%

Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
*/

import java.util.*;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> current = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        
        backtrack(nums, current, used, result);
        return result;
    }
    
    private void backtrack(int[] nums, List<Integer> current, boolean[] used, List<List<Integer>> result) {
        // Base case: if current permutation is complete
        if (current.size() == nums.length) {
            result.add(new ArrayList<>(current));
            return;
        }
        
        // Try each unused number
        for (int i = 0; i < nums.length; i++) {
            if (used[i]) continue;
            
            // Choose
            current.add(nums[i]);
            used[i] = true;
            
            // Explore
            backtrack(nums, current, used, result);
            
            // Unchoose (backtrack)
            current.remove(current.size() - 1);
            used[i] = false;
        }
    }
}
