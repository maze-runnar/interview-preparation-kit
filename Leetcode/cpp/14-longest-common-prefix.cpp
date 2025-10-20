/*
Problem 14: Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
- 1 <= strs.length <= 200
- 0 <= strs[i].length <= 200
- strs[i] consists of only lowercase English letters.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    // Approach 1: Horizontal scanning
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }

        std::string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        return prefix;
    }

    // Approach 2: Vertical scanning
    std::string longestCommonPrefixVertical(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }

        for (int i = 0; i < strs[0].length(); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i == strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }

    // Approach 3: Divide and Conquer
    std::string longestCommonPrefixDivideConquer(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }
        return longestCommonPrefixRecursive(strs, 0, strs.size() - 1);
    }

private:
    std::string longestCommonPrefixRecursive(const std::vector<std::string>& strs, int left, int right) {
        if (left == right) {
            return strs[left];
        }

        int mid = (left + right) / 2;
        std::string lcpLeft = longestCommonPrefixRecursive(strs, left, mid);
        std::string lcpRight = longestCommonPrefixRecursive(strs, mid + 1, right);
        return commonPrefix(lcpLeft, lcpRight);
    }

    std::string commonPrefix(const std::string& str1, const std::string& str2) {
        int minLength = std::min(str1.length(), str2.length());
        for (int i = 0; i < minLength; ++i) {
            if (str1[i] != str2[i]) {
                return str1.substr(0, i);
            }
        }
        return str1.substr(0, minLength);
    }
};

int main() {
    Solution sol;

    std::cout << "Testing Longest Common Prefix (Horizontal Scanning):\n";
    std::vector<std::string> strs1 = {"flower", "flow", "flight"};
    std::cout << "Input: [\"flower\",\"flow\",\"flight\"] -> Output: " << sol.longestCommonPrefix(strs1) << " (Expected: fl)\n";

    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    std::cout << "Input: [\"dog\",\"racecar\",\"car\"] -> Output: " << sol.longestCommonPrefix(strs2) << " (Expected: )\n";

    std::vector<std::string> strs3 = {"apple", "apricot", "april"};
    std::cout << "Input: [\"apple\",\"apricot\",\"april\"] -> Output: " << sol.longestCommonPrefix(strs3) << " (Expected: ap)\n";
    
    std::cout << "\nTesting Longest Common Prefix (Vertical Scanning):\n";
    std::vector<std::string> strs4 = {"flower", "flow", "flight"};
    std::cout << "Input: [\"flower\",\"flow\",\"flight\"] -> Output: " << sol.longestCommonPrefixVertical(strs4) << " (Expected: fl)\n";

    std::vector<std::string> strs5 = {"dog", "racecar", "car"};
    std::cout << "Input: [\"dog\",\"racecar\",\"car\"] -> Output: " << sol.longestCommonPrefixVertical(strs5) << " (Expected: )\n";

    std::vector<std::string> strs6 = {"apple", "apricot", "april"};
    std::cout << "Input: [\"apple\",\"apricot\",\"april\"] -> Output: " << sol.longestCommonPrefixVertical(strs6) << " (Expected: ap)\n";

    std::cout << "\nTesting Longest Common Prefix (Divide and Conquer):\n";
    std::vector<std::string> strs7 = {"flower", "flow", "flight"};
    std::cout << "Input: [\"flower\",\"flow\",\"flight\"] -> Output: " << sol.longestCommonPrefixDivideConquer(strs7) << " (Expected: fl)\n";

    std::vector<std::string> strs8 = {"dog", "racecar", "car"};
    std::cout << "Input: [\"dog\",\"racecar\",\"car\"] -> Output: " << sol.longestCommonPrefixDivideConquer(strs8) << " (Expected: )\n";

    std::vector<std::string> strs9 = {"apple", "apricot", "april"};
    std::cout << "Input: [\"apple\",\"apricot\",\"april\"] -> Output: " << sol.longestCommonPrefixDivideConquer(strs9) << " (Expected: ap)\n";

    return 0;
}
