import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the sum of first three elements

        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (Math.abs(target - currentSum) < Math.abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else { // currentSum == target, perfect match
                    return target;
                }
            }
        }

        return closestSum;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing 3Sum Closest:");

        int[] nums1 = {-1, 2, 1, -4};
        int target1 = 1;
        System.out.println("Input: nums = [-1,2,1,-4], target = 1 -> Output: " + sol.threeSumClosest(nums1, target1) + " (Expected: 2)");

        int[] nums2 = {0, 0, 0};
        int target2 = 1;
        System.out.println("Input: nums = [0,0,0], target = 1 -> Output: " + sol.threeSumClosest(nums2, target2) + " (Expected: 0)");

        int[] nums3 = {1, 1, -1, -1, 3};
        int target3 = -1;
        System.out.println("Input: nums = [1,1,-1,-1,3], target = -1 -> Output: " + sol.threeSumClosest(nums3, target3) + " (Expected: -1)");

        int[] nums4 = {1, 1, -1, -4};
        int target4 = 1;
        System.out.println("Input: nums = [1,1,-1,-4], target = 1 -> Output: " + sol.threeSumClosest(nums4, target4) + " (Expected: 2)");
    }
}
