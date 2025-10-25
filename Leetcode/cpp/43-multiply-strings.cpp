/*
43. Multiply Strings
Medium - 42.9%

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.length(), n = num2.length();
        vector<int> result(m + n, 0);
        
        // Reverse both strings for easier calculation
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        // Multiply each digit
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos1 = i + j, pos2 = i + j + 1;
                
                mul += result[pos1];
                result[pos1] = mul % 10;
                result[pos2] += mul / 10;
            }
        }
        
        // Convert result to string
        string res = "";
        for (int i = result.size() - 1; i >= 0; i--) {
            if (!(res.empty() && result[i] == 0)) {
                res += to_string(result[i]);
            }
        }
        
        return res.empty() ? "0" : res;
    }
};
