"""
39. Combination Sum
Medium - 75.5%

Given an array of distinct integers candidates and a target integer target, return a list of 
all unique combinations of candidates where the chosen numbers sum to target. You may return 
the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations 
are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target 
is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 can be used multiple times.
2 + 2 + 3 = 7
7 = 7
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []
"""

from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        combination = []
        
        # Sort to enable early termination
        candidates.sort()
        
        self.backtrack(candidates, target, 0, combination, result)
        return result
    
    def backtrack(self, candidates: List[int], target: int, start: int, 
                  combination: List[int], result: List[List[int]]) -> None:
        if target == 0:
            result.append(combination[:])  # Add a copy of current combination
            return
        
        for i in range(start, len(candidates)):
            # Early termination if current candidate exceeds target
            if candidates[i] > target:
                break
            
            combination.append(candidates[i])
            # Use same index i to allow reuse of same element
            self.backtrack(candidates, target - candidates[i], i, combination, result)
            combination.pop()  # backtrack
