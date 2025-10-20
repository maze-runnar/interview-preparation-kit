/*
Problem 28: Find the Index of the First Occurrence in a String
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
- 1 <= haystack.length, needle.length <= 10^4
- haystack and needle consist of only lowercase English characters.
*/

#include <string>
#include <iostream>

class Solution {
public:
    // Approach 1: Built-in function (std::string::find)
    int strStrBuiltIn(std::string haystack, std::string needle) {
        size_t found = haystack.find(needle);
        if (found != std::string::npos) {
            return static_cast<int>(found);
        } else {
            return -1;
        }
    }

    // Approach 2: Two Pointers (Naive Approach)
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.empty()) {
            return -1;
        }

        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; ++i) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    std::cout << "Testing Find the Index of the First Occurrence in a String (Naive):\n";

    // Test 1
    std::string haystack1 = "sadbutsad";
    std::string needle1 = "sad";
    std::cout << "Input: haystack = \"" << haystack1 << "\", needle = \"" << needle1 << "\" -> Output: " << sol.strStr(haystack1, needle1) << " (Expected: 0)\n";

    // Test 2
    std::string haystack2 = "leetcode";
    std::string needle2 = "leeto";
    std::cout << "Input: haystack = \"" << haystack2 << "\", needle = \"" << needle2 << "\" -> Output: " << sol.strStr(haystack2, needle2) << " (Expected: -1)\n";

    // Test 3
    std::string haystack3 = "hello";
    std::string needle3 = "ll";
    std::cout << "Input: haystack = \"" << haystack3 << "\", needle = \"" << needle3 << "\" -> Output: " << sol.strStr(haystack3, needle3) << " (Expected: 2)\n";

    // Test 4
    std::string haystack4 = "aaaaa";
    std::string needle4 = "bba";
    std::cout << "Input: haystack = \"" << haystack4 << "\", needle = \"" << needle4 << "\" -> Output: " << sol.strStr(haystack4, needle4) << " (Expected: -1)\n";

    // Test 5
    std::string haystack5 = "";
    std::string needle5 = "a";
    std::cout << "Input: haystack = \"" << haystack5 << "\", needle = \"" << needle5 << "\" -> Output: " << sol.strStr(haystack5, needle5) << " (Expected: -1)\n";

    // Test 6
    std::string haystack6 = "a";
    std::string needle6 = "";
    std::cout << "Input: haystack = \"" << haystack6 << "\", needle = \"" << needle6 << "\" -> Output: " << sol.strStr(haystack6, needle6) << " (Expected: 0)\n";

    std::cout << "\nTesting Find the Index of the First Occurrence in a String (Built-in):\n";

    // Test 7
    std::string haystack7 = "sadbutsad";
    std::string needle7 = "sad";
    std::cout << "Input: haystack = \"" << haystack7 << "\", needle = \"" << needle7 << "\" -> Output: " << sol.strStrBuiltIn(haystack7, needle7) << " (Expected: 0)\n";

    return 0;
}
