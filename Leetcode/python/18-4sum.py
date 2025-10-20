class Solution:
    def fourSum(self, nums: list[int], target: int) -> list[list[int]]:
        result = []
        n = len(nums)
        if n < 4:
            return result

        nums.sort()

        for i in range(n - 3):
            # Skip duplicates for the first element
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1, n - 2):
                # Skip duplicates for the second element
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                left = j + 1
                right = n - 1
                current_target = target - nums[i] - nums[j]

                while left < right:
                    current_sum = nums[left] + nums[right]

                    if current_sum == current_target:
                        result.append([nums[i], nums[j], nums[left], nums[right]])

                        # Skip duplicates for the third and fourth elements
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        left += 1
                        right -= 1
                    elif current_sum < current_target:
                        left += 1
                    else:
                        right -= 1
        
        return result

# Test function
if __name__ == "__main__":
    sol = Solution()

    print("Testing 4Sum:")

    nums1 = [1, 0, -1, 0, -2, 2]
    target1 = 0
    print(f"Input: nums = {nums1}, target = {target1} -> Output: {sol.fourSum(nums1, target1)} (Expected: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]])")

    nums2 = [2, 2, 2, 2, 2]
    target2 = 8
    print(f"Input: nums = {nums2}, target = {target2} -> Output: {sol.fourSum(nums2, target2)} (Expected: [[2,2,2,2]])")

    nums3 = [0, 0, 0, 0]
    target3 = 0
    print(f"Input: nums = {nums3}, target = {target3} -> Output: {sol.fourSum(nums3, target3)} (Expected: [[0,0,0,0]])")

    nums4 = [-5,-4,-3,-2,-1,0,0,1,2,3,4,5]
    target4 = 0
    print(f"Input: nums = {nums4}, target = {target4} -> Output: {sol.fourSum(nums4, target4)} (Expected: [[-5,-4,4,5],[-5,-3,3,5],[-5,-2,2,5],[-5,-2,3,4],[-5,-1,1,5],[-5,-1,2,4],[-5,0,0,5],[-5,0,1,4],[-5,0,2,3],[-4,-3,2,5],[-4,-3,1,4],[-4,-3,0,3],[-4,-2,1,3],[-4,-2,0,2],[-4,-1,0,1],[-3,-2,0,5],[-3,-2,1,4],[-3,-1,1,3],[-3,-1,0,2],[-3,0,0,3],[-3,0,1,2],[-2,-1,0,3],[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]])")
