/*
Problem 12: Integer to Roman
https://leetcode.com/problems/integer-to-roman/

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral.

Example 1:
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.

Example 2:
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:
- 1 <= num <= 3999
*/

#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    // Approach: Greedy Algorithm
    std::string intToRoman(int num) {
        std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::vector<std::string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        std::string result = "";

        for (int i = 0; i < values.size(); ++i) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    std::cout << "Testing Integer to Roman:\n";

    std::cout << "3 -> " << sol.intToRoman(3) << " (Expected: III)\n";
    std::cout << "58 -> " << sol.intToRoman(58) << " (Expected: LVIII)\n";
    std::cout << "1994 -> " << sol.intToRoman(1994) << " (Expected: MCMXCIV)\n";
    std::cout << "9 -> " << sol.intToRoman(9) << " (Expected: IX)\n";
    std::cout << "4 -> " << sol.intToRoman(4) << " (Expected: IV)\n";
    std::cout << "1 -> " << sol.intToRoman(1) << " (Expected: I)\n";
    std::cout << "3999 -> " << sol.intToRoman(3999) << " (Expected: MMMCMXCIX)\n";

    return 0;
}
