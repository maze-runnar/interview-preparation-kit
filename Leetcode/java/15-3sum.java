import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.length < 3) {
            return result;
        }

        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i++) {
            // Skip duplicate for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.length - 1;
            int target = -nums[i];

            while (left < right) {
                int currentSum = nums[left] + nums[right];

                if (currentSum == target) {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));

                    // Skip duplicates for the second and third elements
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing 3Sum:");

        int[] nums1 = {-1, 0, 1, 2, -1, -4};
        System.out.println("Input: [-1,0,1,2,-1,-4] -> Output: " + sol.threeSum(nums1) + " (Expected: [[-1,-1,2],[-1,0,1]])");

        int[] nums2 = {0, 1, 1};
        System.out.println("Input: [0,1,1] -> Output: " + sol.threeSum(nums2) + " (Expected: [])");

        int[] nums3 = {0, 0, 0};
        System.out.println("Input: [0,0,0] -> Output: " + sol.threeSum(nums3) + " (Expected: [[0,0,0]])");

        int[] nums4 = {-2, 0, 1, 1, 2};
        System.out.println("Input: [-2,0,1,1,2] -> Output: " + sol.threeSum(nums4) + " (Expected: [[-2,0,2],[-2,1,1]])");
    }
}
