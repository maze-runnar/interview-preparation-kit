class Solution:
    def maxArea(self, height: list[int]) -> int:
        max_area = 0
        left = 0
        right = len(height) - 1

        while left < right:
            current_height = min(height[left], height[right])
            current_width = right - left
            max_area = max(max_area, current_height * current_width)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        
        return max_area

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Container With Most Water:")

    h1 = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    print(f"Input: {h1} -> Output: {sol.maxArea(h1)} (Expected: 49)")

    h2 = [1, 1]
    print(f"Input: {h2} -> Output: {sol.maxArea(h2)} (Expected: 1)")

    h3 = [4, 3, 2, 1, 4]
    print(f"Input: {h3} -> Output: {sol.maxArea(h3)} (Expected: 16)")

    h4 = [1, 2, 1]
    print(f"Input: {h4} -> Output: {sol.maxArea(h4)} (Expected: 2)")
