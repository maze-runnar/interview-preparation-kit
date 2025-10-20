/*
Problem 7: Reverse Integer
https://leetcode.com/problems/reverse-integer/

Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:
- -2^31 <= x <= 2^31 - 1
*/

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    // Approach 1: Mathematical approach with overflow check
    int reverse(int x) {
        int result = 0;
        
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            
            // Check for overflow before multiplying by 10
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            
            result = result * 10 + pop;
        }
        
        return result;
    }
    
    // Approach 2: Using long long for intermediate calculation
    int reverseLongLong(int x) {
        long long result = 0;
        
        while (x != 0) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        
        // Check if result is within 32-bit integer range
        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }
        
        return (int)result;
    }
};

// Test function
int main() {
    Solution solution;
    
    // Test cases
    vector<int> testCases = {123, -123, 120, 0, 1534236469, -2147483648, 2147483647, 1463847412};
    
    cout << "Testing Reverse Integer:\n";
    cout << "INT_MAX: " << INT_MAX << ", INT_MIN: " << INT_MIN << "\n\n";
    
    for (int test : testCases) {
        int result1 = solution.reverse(test);
        int result2 = solution.reverseLongLong(test);
        cout << "Input: " << test << " -> Output: " << result1;
        cout << " (Long approach: " << result2 << ")";
        cout << " Match: " << (result1 == result2 ? "Yes" : "No") << "\n";
    }
    
    return 0;
}
