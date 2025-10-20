import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        if (n < 4) {
            return result;
        }

        Arrays.sort(nums);

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;
                long currentTarget = (long)target - nums[i] - nums[j]; // Use long for target to prevent overflow

                while (left < right) {
                    long currentSum = (long)nums[left] + nums[right];

                    if (currentSum == currentTarget) {
                        result.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));

                        // Skip duplicates for the third and fourth elements
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (currentSum < currentTarget) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing 4Sum:");

        int[] nums1 = {1, 0, -1, 0, -2, 2};
        int target1 = 0;
        System.out.println("Input: nums = [1,0,-1,0,-2,2], target = 0 -> Output: " + sol.fourSum(nums1, target1) + " (Expected: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]])");

        int[] nums2 = {2, 2, 2, 2, 2};
        int target2 = 8;
        System.out.println("Input: nums = [2,2,2,2,2], target = 8 -> Output: " + sol.fourSum(nums2, target2) + " (Expected: [[2,2,2,2]])");

        int[] nums3 = {0, 0, 0, 0};
        int target3 = 0;
        System.out.println("Input: nums = [0,0,0,0], target = 0 -> Output: " + sol.fourSum(nums3, target3) + " (Expected: [[0,0,0,0]])");

        int[] nums4 = {-5,-4,-3,-2,-1,0,0,1,2,3,4,5};
        int target4 = 0;
        System.out.println("Input: nums = [-5,-4,-3,-2,-1,0,0,1,2,3,4,5], target = 0 -> Output: " + sol.fourSum(nums4, target4) + " (Expected: [[-5,-4,4,5],[-5,-3,3,5],[-5,-2,2,5],[-5,-2,3,4],[-5,-1,1,5],[-5,-1,2,4],[-5,0,0,5],[-5,0,1,4],[-5,0,2,3],[-4,-3,2,5],[-4,-3,1,4],[-4,-3,0,3],[-4,-2,1,3],[-4,-2,0,2],[-4,-1,0,1],[-3,-2,0,5],[-3,-2,1,4],[-3,-1,1,3],[-3,-1,0,2],[-3,0,0,3],[-3,0,1,2],[-2,-1,0,3],[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]])");
    }
}
