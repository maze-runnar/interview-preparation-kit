/*
Problem 6: ZigZag Conversion
https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:

P   A   H   R
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows.

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"

Example 3:
Input: s = "A", numRows = 1
Output: "A"

Constraints:
- 1 <= s.length <= 1000
- s consists of English letters (lower-case and upper-case), ',' and '.'.
- 1 <= numRows <= 1000
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: Visit by Row - O(n) time, O(n) space
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> rows(min(numRows, (int)s.size()));
        int curRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }
        
        string result;
        for (string row : rows) {
            result += row;
        }
        return result;
    }
    
    // Approach 2: Visit by Row (Mathematical) - O(n) time, O(1) extra space
    string convertMath(string s, int numRows) {
        if (numRows == 1) return s;
        
        string result;
        int n = s.length();
        int cycleLen = 2 * numRows - 2;
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                result += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    result += s[j + cycleLen - i];
                }
            }
        }
        
        return result;
    }
};

// Test function
int main() {
    Solution solution;
    
    // Test cases
    vector<pair<string, int>> testCases = {
        {"PAYPALISHIRING", 3},
        {"PAYPALISHIRING", 4},
        {"A", 1},
        {"AB", 1},
        {"ABCDEFGHIJKLMNOP", 4}
    };
    
    cout << "Testing ZigZag Conversion:\n";
    for (const auto& test : testCases) {
        string result1 = solution.convert(test.first, test.second);
        string result2 = solution.convertMath(test.first, test.second);
        cout << "Input: \"" << test.first << "\", numRows: " << test.second 
             << " -> Output: \"" << result1 << "\"\n";
        cout << "Math approach: \"" << result2 << "\"\n";
        cout << "Results match: " << (result1 == result2 ? "Yes" : "No") << "\n\n";
    }
    
    return 0;
}
