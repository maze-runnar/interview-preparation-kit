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

import java.util.*;

class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> current = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        
        // Sort to handle duplicates
        Arrays.sort(nums);
        
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
            
            // Skip duplicates: if current number is same as previous and previous is not used
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            
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
