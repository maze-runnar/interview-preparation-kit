class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0;
        int left = 0;
        int right = height.length - 1;

        while (left < right) {
            int currentHeight = Math.min(height[left], height[right]);
            int currentWidth = right - left;
            maxArea = Math.max(maxArea, currentHeight * currentWidth);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Container With Most Water:");

        int[] h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        System.out.println("Input: [1,8,6,2,5,4,8,3,7] -> Output: " + sol.maxArea(h1) + " (Expected: 49)");

        int[] h2 = {1, 1};
        System.out.println("Input: [1,1] -> Output: " + sol.maxArea(h2) + " (Expected: 1)");

        int[] h3 = {4, 3, 2, 1, 4};
        System.out.println("Input: [4,3,2,1,4] -> Output: " + sol.maxArea(h3) + " (Expected: 16)");

        int[] h4 = {1, 2, 1};
        System.out.println("Input: [1,2,1] -> Output: " + sol.maxArea(h4) + " (Expected: 2)");
    }
}
