"""
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
"""

from typing import List

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        result = []
        current = []
        used = [False] * len(nums)
        
        # Sort to handle duplicates
        nums.sort()
        
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
            
            # Skip duplicates: if current number is same as previous and previous is not used
            if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
                continue
            
            # Choose
            current.append(nums[i])
            used[i] = True
            
            # Explore
            self.backtrack(nums, current, used, result)
            
            # Unchoose (backtrack)
            current.pop()
            used[i] = False
