/*
Problem 13: Roman to Integer
https://leetcode.com/problems/roman-to-integer/

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

Given a Roman numeral, convert it to an integer.

Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:
- 1 <= s.length <= 15
- s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
- It is guaranteed that s is a valid Roman numeral in the range [1, 3999].
*/

#include <string>
#include <map>
#include <iostream>

class Solution {
public:
    // Approach: Iterate from right to left
    int romanToInt(std::string s) {
        std::map<char, int> roman_values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int prev_value = 0;

        // Iterate from right to left
        for (int i = s.length() - 1; i >= 0; --i) {
            int current_value = roman_values[s[i]];

            if (current_value < prev_value) {
                total -= current_value;
            } else {
                total += current_value;
            }
            prev_value = current_value;
        }

        return total;
    }
};

int main() {
    Solution sol;

    std::cout << "Testing Roman to Integer:\n";

    std::cout << "\"III\" -> " << sol.romanToInt("III") << " (Expected: 3)\n";
    std::cout << "\"LVIII\" -> " << sol.romanToInt("LVIII") << " (Expected: 58)\n";
    std::cout << "\"MCMXCIV\" -> " << sol.romanToInt("MCMXCIV") << " (Expected: 1994)\n";
    std::cout << "\"IX\" -> " << sol.romanToInt("IX") << " (Expected: 9)\n";
    std::cout << "\"IV\" -> " << sol.romanToInt("IV") << " (Expected: 4)\n";
    std::cout << "\"I\" -> " << sol.romanToInt("I") << " (Expected: 1)\n";
    std::cout << "\"MMMCMXCIX\" -> " << sol.romanToInt("MMMCMXCIX") << " (Expected: 3999)\n";

    return 0;
}
