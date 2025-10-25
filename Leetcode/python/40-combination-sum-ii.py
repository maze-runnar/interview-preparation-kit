"""
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
"""

from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        combination = []
        
        # Sort to handle duplicates and enable early termination
        candidates.sort()
        
        self.backtrack(candidates, target, 0, combination, result)
        return result
    
    def backtrack(self, candidates: List[int], target: int, start: int, 
                  combination: List[int], result: List[List[int]]) -> None:
        if target == 0:
            result.append(combination[:])  # Add a copy of current combination
            return
        
        for i in range(start, len(candidates)):
            # Skip duplicates: if current element is same as previous and we haven't used previous
            if i > start and candidates[i] == candidates[i - 1]:
                continue
            
            # Early termination if current candidate exceeds target
            if candidates[i] > target:
                break
            
            combination.append(candidates[i])
            # Use i + 1 to avoid reusing same element (each number used only once)
            self.backtrack(candidates, target - candidates[i], i + 1, combination, result)
            combination.pop()  # backtrack
