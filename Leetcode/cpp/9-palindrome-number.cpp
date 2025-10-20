/*
Problem 9: Palindrome Number
https://leetcode.com/problems/palindrome-number/

Given an integer x, return true if x is a 
Palindrome Number
, and false otherwise.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:
- -2^31 <= x <= 2^31 - 1
*/

#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    // Approach 1: Convert to string and compare
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        std::string s = std::to_string(x);
        std::string reversed_s = s;
        std::reverse(reversed_s.begin(), reversed_s.end());
        return s == reversed_s;
    }

    // Approach 2: Revert half of the number
    bool isPalindromeMath(int x) {
        // Special cases: negative numbers are not palindromes
        // If x is a multiple of 10 (except 0 itself), it cannot be a palindrome
        // (e.g., 10, 20, 100). The reversed number would start with a 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example, when the input is 12321, at the end of the while loop we get x = 12, and revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(odd number of digits),
        // we could simply revertNumber/10 and compare it with x.
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

int main() {
    Solution sol;

    std::cout << "Testing Palindrome Number:\n";

    std::cout << "121: " << (sol.isPalindrome(121) ? "true" : "false") << " (Expected: true)\n";
    std::cout << "-121: " << (sol.isPalindrome(-121) ? "true" : "false") << " (Expected: false)\n";
    std::cout << "10: " << (sol.isPalindrome(10) ? "true" : "false") << " (Expected: false)\n";
    std::cout << "0: " << (sol.isPalindrome(0) ? "true" : "false") << " (Expected: true)\n";
    std::cout << "12321: " << (sol.isPalindrome(12321) ? "true" : "false") << " (Expected: true)\n";
    std::cout << "123321: " << (sol.isPalindrome(123321) ? "true" : "false") << " (Expected: true)\n";
    std::cout << "12345: " << (sol.isPalindrome(12345) ? "true" : "false") << " (Expected: false)\n";

    std::cout << "\nTesting Palindrome Number (Math Approach):\n";

    std::cout << "121: " << (sol.isPalindromeMath(121) ? "true" : "false") << " (Expected: true)\n";
    std::cout << "-121: " << (sol.isPalindromeMath(-121) ? "true" : "false") << " (Expected: false)\n";
    std::cout << "10: " << (sol.isPalindromeMath(10) ? "true" : "false") << " (Expected: false)\n";
    std::cout << "0: " << (sol.isPalindromeMath(0) ? "true" : "false") << " (Expected: true)\n";
    std::cout << "12321: " << (sol.isPalindromeMath(12321) ? "true" : "false") << " (Expected: true)\n";
    std::cout << "123321: " << (sol.isPalindromeMath(123321) ? "true" : "false") << " (Expected: true)\n";
    std::cout << "12345: " << (sol.isPalindromeMath(12345) ? "true" : "false") << " (Expected: false)\n";

    return 0;
}
