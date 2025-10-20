/*
Problem 8: String to Integer (atoi)
https://leetcode.com/problems/string-to-integer-atoi/

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is '-' or '+'. 
   Read this character in if it is either. This determines if the final result is negative or positive respectively. 
   Assume the result is positive if neither is present.
3. Read in next the characters until the next non-digit character or the end of the input is reached. 
   The rest of the string is ignored.
4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). 
   If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
5. If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], 
   then clamp the integer so that it remains in the range. 
   Specifically, integers less than -2^31 should be clamped to -2^31, 
   and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
6. Return the integer as the final result.

Example 1:
Input: s = "42"
Output: 42

Example 2:
Input: s = "   -42"
Output: -42

Example 3:
Input: s = "4193 with words"
Output: 4193

Constraints:
- 0 <= s.length <= 200
- s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Check for sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3 & 4: Read digits and convert to integer
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Step 5: Check for overflow during calculation
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && result > (long long)INT_MAX + 1) {
                return INT_MIN;
            }
            
            i++;
        }
        
        return (int)(sign * result);
    }
    
    // Alternative approach without using long long
    int myAtoiNoLongLong(string s) {
        int i = 0;
        int n = s.length();
        
        // Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Check for sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Read digits and convert to integer
        int result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for overflow before multiplying by 10
            if (result > INT_MAX / 10 || 
                (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return sign * result;
    }
};

// Test function
int main() {
    Solution solution;
    
    // Test cases
    vector<string> testCases = {
        "42",
        "   -42",
        "4193 with words",
        "words and 987",
        "-91283472332",
        "91283472332",
        "+1",
        "+-12",
        "00000-42a1234",
        "   +0 123",
        "2147483648",
        "-2147483649",
        "2147483647",
        "-2147483648"
    };
    
    cout << "Testing String to Integer (atoi):\n";
    cout << "INT_MAX: " << INT_MAX << ", INT_MIN: " << INT_MIN << "\n\n";
    
    for (const string& test : testCases) {
        int result1 = solution.myAtoi(test);
        int result2 = solution.myAtoiNoLongLong(test);
        cout << "Input: \"" << test << "\" -> Output: " << result1;
        cout << " (No long long: " << result2 << ")";
        cout << " Match: " << (result1 == result2 ? "Yes" : "No") << "\n";
    }
    
    return 0;
}
