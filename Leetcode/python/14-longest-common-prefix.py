class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        if not strs:
            return ""

        prefix = strs[0]
        for i in range(1, len(strs)):
            while strs[i].find(prefix) != 0:
                prefix = prefix[:-1]
                if not prefix:
                    return ""
        return prefix

    def longestCommonPrefixVertical(self, strs: list[str]) -> str:
        if not strs:
            return ""

        for i in range(len(strs[0])):
            char = strs[0][i]
            for j in range(1, len(strs)):
                if i == len(strs[j]) or strs[j][i] != char:
                    return strs[0][:i]
        return strs[0]

    def longestCommonPrefixDivideConquer(self, strs: list[str]) -> str:
        if not strs:
            return ""

        def longest_common_prefix_recursive(strs_list, left, right):
            if left == right:
                return strs_list[left]

            mid = (left + right) // 2
            lcp_left = longest_common_prefix_recursive(strs_list, left, mid)
            lcp_right = longest_common_prefix_recursive(strs_list, mid + 1, right)
            return common_prefix(lcp_left, lcp_right)

        def common_prefix(str1, str2):
            min_length = min(len(str1), len(str2))
            for i in range(min_length):
                if str1[i] != str2[i]:
                    return str1[:i]
            return str1[:min_length]

        return longest_common_prefix_recursive(strs, 0, len(strs) - 1)

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Longest Common Prefix (Horizontal Scanning):")
    strs1 = ["flower", "flow", "flight"]
    print(f"Input: {strs1} -> Output: {sol.longestCommonPrefix(strs1)} (Expected: fl)")

    strs2 = ["dog", "racecar", "car"]
    print(f"Input: {strs2} -> Output: {sol.longestCommonPrefix(strs2)} (Expected: )")

    strs3 = ["apple", "apricot", "april"]
    print(f"Input: {strs3} -> Output: {sol.longestCommonPrefix(strs3)} (Expected: ap)")
    
    print("\nTesting Longest Common Prefix (Vertical Scanning):")
    strs4 = ["flower", "flow", "flight"]
    print(f"Input: {strs4} -> Output: {sol.longestCommonPrefixVertical(strs4)} (Expected: fl)")

    strs5 = ["dog", "racecar", "car"]
    print(f"Input: {strs5} -> Output: {sol.longestCommonPrefixVertical(strs5)} (Expected: )")

    strs6 = ["apple", "apricot", "april"]
    print(f"Input: {strs6} -> Output: {sol.longestCommonPrefixVertical(strs6)} (Expected: ap)")

    print("\nTesting Longest Common Prefix (Divide and Conquer):")
    strs7 = ["flower", "flow", "flight"]
    print(f"Input: {strs7} -> Output: {sol.longestCommonPrefixDivideConquer(strs7)} (Expected: fl)")

    strs8 = ["dog", "racecar", "car"]
    print(f"Input: {strs8} -> Output: {sol.longestCommonPrefixDivideConquer(strs8)} (Expected: )")

    strs9 = ["apple", "apricot", "april"]
    print(f"Input: {strs9} -> Output: {sol.longestCommonPrefixDivideConquer(strs9)} (Expected: ap)")
