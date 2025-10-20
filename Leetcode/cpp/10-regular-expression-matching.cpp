/*
Problem 10: Regular Expression Matching
https://leetcode.com/problems/regular-expression-matching/

Given an input string s and a pattern p, implement regular expression matching with the following capabilities:

- '.' Matches any single character.
- '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Constraints:
- 1 <= s.length <= 20
- 1 <= p.length <= 30
- s contains only lowercase English letters.
- p contains only lowercase English letters, '.', and '*'
- It is guaranteed that for every instance of the character '*' in p, there will be a previous valid character to match.
*/

#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    // Approach: Dynamic Programming
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();

        // dp[i][j] will be true if s[0...i-1] matches p[0...j-1]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        // Empty string matches empty pattern
        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c*
        // dp[0][j] is true if p[0...j-1] is of the form x*y*z*...
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // Case 1: The '*' matches zero preceding element.
                    // In this case, we ignore the preceding element and the '*'.
                    dp[i][j] = dp[i][j - 2];

                    // Case 2: The '*' matches one or more preceding element.
                    // This is only possible if the current character in 's' matches the preceding character in 'p'
                    // (or the preceding character in 'p' is '.').
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;

    // Test cases
    std::cout << "Testing Regular Expression Matching:\n";

    std::cout << "s = \"aa\", p = \"a\" -> " << (sol.isMatch("aa", "a") ? "true" : "false") << " (Expected: false)\n";
    std::cout << "s = \"aa\", p = \"a*\" -> " << (sol.isMatch("aa", "a*") ? "true" : "false") << " (Expected: true)\n";
    std::cout << "s = \"ab\", p = \".*\" -> " << (sol.isMatch("ab", ".*") ? "true" : "false") << " (Expected: true)\n";
    std::cout << "s = \"aab\", p = \"c*a*b\" -> " << (sol.isMatch("aab", "c*a*b") ? "true" : "false") << " (Expected: true)\n";
    std::cout << "s = \"mississippi\", p = \"mis*is*p*.\" -> " << (sol.isMatch("mississippi", "mis*is*p*.") ? "true" : "false") << " (Expected: false)\n";
    std::cout << "s = \"ab\", p = \".*c\" -> " << (sol.isMatch("ab", ".*c") ? "true" : "false") << " (Expected: false)\n";
    std::cout << "s = \"aaa\", p = \"a*a\" -> " << (sol.isMatch("aaa", "a*a") ? "true" : "false") << " (Expected: true)\n";
    std::cout << "s = \"aaa\", p = \"ab*a*c*a\" -> " << (sol.isMatch("aaa", "ab*a*c*a") ? "true" : "false") << " (Expected: true)\n";
    std::cout << "s = \"a\", p = \"ab*\" -> " << (sol.isMatch("a", "ab*") ? "true" : "false") << " (Expected: true)\n";

    return 0;
}
