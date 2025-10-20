class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        if not nums:
            return 0
        
        i = 0 # Slow pointer, keeps track of the position for the next unique element
        for j in range(1, len(nums)): # Fast pointer, iterates through the array
            if nums[j] != nums[i]:
                i += 1
                nums[i] = nums[j]
        
        return i + 1

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Remove Duplicates from Sorted Array:")

    # Test 1
    nums1 = [1, 1, 2]
    k1 = sol.removeDuplicates(nums1)
    print(f"Input: [1,1,2] -> Output: {k1}, nums = {nums1[:k1]} (Expected: 2, nums = [1,2,_])")

    # Test 2
    nums2 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    k2 = sol.removeDuplicates(nums2)
    print(f"Input: [0,0,1,1,1,2,2,3,3,4] -> Output: {k2}, nums = {nums2[:k2]} (Expected: 5, nums = [0,1,2,3,4,_,_,_,_,_])")

    # Test 3
    nums3 = [1, 1, 1, 1, 1]
    k3 = sol.removeDuplicates(nums3)
    print(f"Input: [1,1,1,1,1] -> Output: {k3}, nums = {nums3[:k3]} (Expected: 1, nums = [1])")

    # Test 4
    nums4 = [1, 2, 3, 4, 5]
    k4 = sol.removeDuplicates(nums4)
    print(f"Input: [1,2,3,4,5] -> Output: {k4}, nums = {nums4[:k4]} (Expected: 5, nums = [1,2,3,4,5])")

    # Test 5
    nums5 = []
    k5 = sol.removeDuplicates(nums5)
    print(f"Input: [] -> Output: {k5}, nums = {nums5[:k5]} (Expected: 0, nums = [])")
