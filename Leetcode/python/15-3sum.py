class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        result = []
        if len(nums) < 3:
            return result

        nums.sort()

        for i in range(len(nums) - 2):
            # Skip duplicate for the first element
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left = i + 1
            right = len(nums) - 1
            target = -nums[i]

            while left < right:
                current_sum = nums[left] + nums[right]

                if current_sum == target:
                    result.append([nums[i], nums[left], nums[right]])

                    # Skip duplicates for the second and third elements
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif current_sum < target:
                    left += 1
                else:
                    right -= 1
        
        return result

# Test function
if __name__ == "__main__":
    sol = Solution()

    print("Testing 3Sum:")

    nums1 = [-1, 0, 1, 2, -1, -4]
    print(f"Input: {nums1} -> Output: {sol.threeSum(nums1)} (Expected: [[-1,-1,2],[-1,0,1]])")

    nums2 = [0, 1, 1]
    print(f"Input: {nums2} -> Output: {sol.threeSum(nums2)} (Expected: [])")

    nums3 = [0, 0, 0]
    print(f"Input: {nums3} -> Output: {sol.threeSum(nums3)} (Expected: [[0,0,0]])")

    nums4 = [-2, 0, 1, 1, 2]
    print(f"Input: {nums4} -> Output: {sol.threeSum(nums4)} (Expected: [[-2,0,2],[-2,1,1]])")
