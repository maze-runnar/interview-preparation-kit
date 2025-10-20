class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:
        nums.sort()
        closest_sum = nums[0] + nums[1] + nums[2] # Initialize with the sum of first three elements

        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1

            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]

                if abs(target - current_sum) < abs(target - closest_sum):
                    closest_sum = current_sum
                
                if current_sum < target:
                    left += 1
                elif current_sum > target:
                    right -= 1
                else: # current_sum == target, perfect match
                    return target

        return closest_sum

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing 3Sum Closest:")

    nums1 = [-1, 2, 1, -4]
    target1 = 1
    print(f"Input: nums = {nums1}, target = {target1} -> Output: {sol.threeSumClosest(nums1, target1)} (Expected: 2)")

    nums2 = [0, 0, 0]
    target2 = 1
    print(f"Input: nums = {nums2}, target = {target2} -> Output: {sol.threeSumClosest(nums2, target2)} (Expected: 0)")

    nums3 = [1, 1, -1, -1, 3]
    target3 = -1
    print(f"Input: nums = {nums3}, target = {target3} -> Output: {sol.threeSumClosest(nums3, target3)} (Expected: -1)")

    nums4 = [1, 1, -1, -4]
    target4 = 1
    print(f"Input: nums = {nums4}, target = {target4} -> Output: {sol.threeSumClosest(nums4, target4)} (Expected: 2)")
