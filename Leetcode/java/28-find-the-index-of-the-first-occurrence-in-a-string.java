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

class Solution {
    // Approach 1: Built-in function (String.indexOf)
    public int strStrBuiltIn(String haystack, String needle) {
        return haystack.indexOf(needle);
    }

    // Approach 2: Two Pointers (Naive Approach)
    public int strStr(String haystack, String needle) {
        if (needle.isEmpty()) {
            return 0;
        }
        if (haystack.isEmpty()) {
            return -1;
        }

        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; i++) {
            boolean match = true;
            for (int j = 0; j < m; j++) {
                if (haystack.charAt(i + j) != needle.charAt(j)) {
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

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Find the Index of the First Occurrence in a String (Naive):\n");

        // Test 1
        String haystack1 = "sadbutsad";
        String needle1 = "sad";
        System.out.println("Input: haystack = \"" + haystack1 + "\", needle = \"" + needle1 + "\" -> Output: " + sol.strStr(haystack1, needle1) + " (Expected: 0)");

        // Test 2
        String haystack2 = "leetcode";
        String needle2 = "leeto";
        System.out.println("Input: haystack = \"" + haystack2 + "\", needle = \"" + needle2 + "\" -> Output: " + sol.strStr(haystack2, needle2) + " (Expected: -1)");

        // Test 3
        String haystack3 = "hello";
        String needle3 = "ll";
        System.out.println("Input: haystack = \"" + haystack3 + "\", needle = \"" + needle3 + "\" -> Output: " + sol.strStr(haystack3, needle3) + " (Expected: 2)");

        // Test 4
        String haystack4 = "aaaaa";
        String needle4 = "bba";
        System.out.println("Input: haystack = \"" + haystack4 + "\", needle = \"" + needle4 + "\" -> Output: " + sol.strStr(haystack4, needle4) + " (Expected: -1)");

        // Test 5
        String haystack5 = "";
        String needle5 = "a";
        System.out.println("Input: haystack = \"" + haystack5 + "\", needle = \"" + needle5 + "\" -> Output: " + sol.strStr(haystack5, needle5) + " (Expected: -1)");

        // Test 6
        String haystack6 = "a";
        String needle6 = "";
        System.out.println("Input: haystack = \"" + haystack6 + "\", needle = \"" + needle6 + "\" -> Output: " + sol.strStr(haystack6, needle6) + " (Expected: 0)");

        System.out.println("\nTesting Find the Index of the First Occurrence in a String (Built-in):\n");

        // Test 7
        String haystack7 = "sadbutsad";
        String needle7 = "sad";
        System.out.println("Input: haystack = \"" + haystack7 + "\", needle = \"" + needle7 + "\" -> Output: " + sol.strStrBuiltIn(haystack7, needle7) + " (Expected: 0)");
    }
}
