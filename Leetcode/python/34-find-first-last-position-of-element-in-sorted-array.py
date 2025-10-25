"""
34. Find First and Last Position of Element in Sorted Array
Medium - 42.9%

Given an array of integers nums sorted in non-decreasing order, find the starting and ending 
position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
"""

from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1, -1]
        
        # Find first position
        first = self.find_first(nums, target)
        if first == -1:
            return [-1, -1]
        
        # Find last position
        last = self.find_last(nums, target)
        
        return [first, last]
    
    def find_first(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        first = -1
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if nums[mid] == target:
                first = mid
                right = mid - 1  # Continue searching left for first occurrence
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return first
    
    def find_last(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        last = -1
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if nums[mid] == target:
                last = mid
                left = mid + 1  # Continue searching right for last occurrence
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return last
