"""
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
"""

from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        current = []
        used = [False] * len(nums)
        
        self.backtrack(nums, current, used, result)
        return result
    
    def backtrack(self, nums: List[int], current: List[int], used: List[bool], result: List[List[int]]) -> None:
        # Base case: if current permutation is complete
        if len(current) == len(nums):
            result.append(current[:])  # Add a copy of current permutation
            return
        
        # Try each unused number
        for i in range(len(nums)):
            if used[i]:
                continue
            
            # Choose
            current.append(nums[i])
            used[i] = True
            
            # Explore
            self.backtrack(nums, current, used, result)
            
            # Unchoose (backtrack)
            current.pop()
            used[i] = False
