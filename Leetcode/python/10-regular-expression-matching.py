class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo = {}

        def dp(i, j):
            if (i, j) in memo:
                return memo[(i, j)]

            if j == len(p):
                return i == len(s)

            first_match = (i < len(s) and (p[j] == s[i] or p[j] == '.'))

            if j + 1 < len(p) and p[j + 1] == '*':
                # Case 1: The '*' matches zero preceding element. (dp(i, j+2))
                # Case 2: The '*' matches one or more preceding element. (first_match and dp(i+1, j))
                result = dp(i, j + 2) or (first_match and dp(i + 1, j))
            else:
                result = first_match and dp(i + 1, j + 1)

            memo[(i, j)] = result
            return result

        return dp(0, 0)

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Regular Expression Matching:")

    print(f"s = \"aa\", p = \"a\" -> {sol.isMatch("aa", "a")} (Expected: False)")
    print(f"s = \"aa\", p = \"a*\" -> {sol.isMatch("aa", "a*")} (Expected: True)")
    print(f"s = \"ab\", p = \".*\" -> {sol.isMatch("ab", ".*")} (Expected: True)")
    print(f"s = \"aab\", p = \"c*a*b\" -> {sol.isMatch("aab", "c*a*b")} (Expected: True)")
    print(f"s = \"mississippi\", p = \"mis*is*p*.\" -> {sol.isMatch("mississippi", "mis*is*p*.")} (Expected: False)")
    print(f"s = \"ab\", p = \".*c\" -> {sol.isMatch("ab", ".*c")} (Expected: False)")
    print(f"s = \"aaa\", p = \"a*a\" -> {sol.isMatch("aaa", "a*a")} (Expected: True)")
    print(f"s = \"aaa\", p = \"ab*a*c*a\" -> {sol.isMatch("aaa", "ab*a*c*a")} (Expected: True)")
    print(f"s = \"a\", p = \"ab*\" -> {sol.isMatch("a", "ab*")} (Expected: True)")
