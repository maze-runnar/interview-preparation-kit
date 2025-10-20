class Solution:
    # Approach 1: Two Pointers (when elements to remove are rare)
    def removeElementTwoPointers(self, nums: list[int], val: int) -> int:
        i = 0
        n = len(nums)
        while i < n:
            if nums[i] == val:
                nums[i] = nums[n - 1]  # Move the last element to the current position
                # Reduce array size by one
                n -= 1
            else:
                i += 1
        return n

    # Approach 2: Two Pointers (when elements to remove are frequent)
    def removeElement(self, nums: list[int], val: int) -> int:
        i = 0  # Slow pointer, indicates the position to place the next non-val element
        for j in range(len(nums)):  # Fast pointer, iterates through the array
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
        return i

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Remove Element (Two Pointers - frequent):\n")

    # Test 1
    nums1 = [3, 2, 2, 3]
    val1 = 3
    k1 = sol.removeElement(nums1, val1)
    print(f"Input: nums = [3,2,2,3], val = 3 -> Output: {k1}, nums = {nums1[:k1]} (Expected: 2, nums = [2,2])")

    # Test 2
    nums2 = [0, 1, 2, 2, 3, 0, 4, 2]
    val2 = 2
    k2 = sol.removeElement(nums2, val2)
    print(f"Input: nums = [0,1,2,2,3,0,4,2], val = 2 -> Output: {k2}, nums = {nums2[:k2]} (Expected: 5, nums = [0,1,4,0,3] or similar)")

    # Test 3
    nums3 = []
    val3 = 0
    k3 = sol.removeElement(nums3, val3)
    print(f"Input: nums = [], val = 0 -> Output: {k3}, nums = {nums3[:k3]} (Expected: 0, nums = [])")

    # Test 4
    nums4 = [1]
    val4 = 1
    k4 = sol.removeElement(nums4, val4)
    print(f"Input: nums = [1], val = 1 -> Output: {k4}, nums = {nums4[:k4]} (Expected: 0, nums = [])")

    print("\nTesting Remove Element (Two Pointers - rare):\n")

    # Test 5
    nums5 = [3, 2, 2, 3]
    val5 = 3
    k5 = sol.removeElementTwoPointers(nums5, val5)
    print(f"Input: nums = [3,2,2,3], val = 3 -> Output: {k5}, nums = {nums5[:k5]} (Expected: 2, nums = [2,2])")

    # Test 6
    nums6 = [0, 1, 2, 2, 3, 0, 4, 2]
    val6 = 2
    k6 = sol.removeElementTwoPointers(nums6, val6)
    print(f"Input: nums = [0,1,2,2,3,0,4,2], val = 2 -> Output: {k6}, nums = {nums6[:k6]} (Expected: 5, nums = [0,1,4,0,3] or similar)")
