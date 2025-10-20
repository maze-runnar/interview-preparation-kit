/*
Problem 29: Divide Two Integers
https://leetcode.com/problems/divide-two-integers/

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Handle overflow cases. If the answer is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the answer is strictly less than -2^31, then return -2^31.

Constraints:
- -2^31 <= dividend, divisor <= 2^31 - 1
- divisor != 0
*/

#include <climits> // For INT_MAX and INT_MIN
#include <cmath>   // For std::abs
#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge cases for overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Overflow case: -2^31 / -1 = 2^31 which is INT_MAX + 1
        }

        // Determine the sign of the result
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        // Convert to long long to handle absolute values of INT_MIN without overflow
        long long ldividend = std::abs(static_cast<long long>(dividend));
        long long ldivisor = std::abs(static_cast<long long>(divisor));

        long long quotient = 0;

        // Repeatedly subtract divisor from dividend
        while (ldividend >= ldivisor) {
            long long temp_divisor = ldivisor;
            long long multiple = 1;
            // Find the largest multiple of divisor that is less than or equal to dividend
            while (ldividend >= (temp_divisor << 1) && (temp_divisor << 1) > 0) { // (temp_divisor << 1) > 0 to prevent overflow
                temp_divisor <<= 1;
                multiple <<= 1;
            }
            ldividend -= temp_divisor;
            quotient += multiple;
        }

        // Apply the sign
        return static_cast<int>(sign * quotient);
    }
};

int main() {
    Solution sol;

    std::cout << "Testing Divide Two Integers:\n";

    // Test 1
    std::cout << "Input: dividend = 10, divisor = 3 -> Output: " << sol.divide(10, 3) << " (Expected: 3)\n";

    // Test 2
    std::cout << "Input: dividend = 7, divisor = -3 -> Output: " << sol.divide(7, -3) << " (Expected: -2)\n";

    // Test 3
    std::cout << "Input: dividend = 0, divisor = 1 -> Output: " << sol.divide(0, 1) << " (Expected: 0)\n";

    // Test 4: Edge case - dividend is INT_MIN, divisor is -1
    std::cout << "Input: dividend = -2147483648, divisor = -1 -> Output: " << sol.divide(INT_MIN, -1) << " (Expected: 2147483647)\n";

    // Test 5: Edge case - dividend is INT_MIN, divisor is 1
    std::cout << "Input: dividend = -2147483648, divisor = 1 -> Output: " << sol.divide(INT_MIN, 1) << " (Expected: -2147483648)\n";

    // Test 6: Standard positive division
    std::cout << "Input: dividend = 100, divisor = 5 -> Output: " << sol.divide(100, 5) << " (Expected: 20)\n";

    // Test 7: Negative dividend, positive divisor
    std::cout << "Input: dividend = -29, divisor = 3 -> Output: " << sol.divide(-29, 3) << " (Expected: -9)\n";

    // Test 8: Positive dividend, negative divisor
    std::cout << "Input: dividend = 29, divisor = -3 -> Output: " << sol.divide(29, -3) << " (Expected: -9)\n";

    // Test 9: Both negative
    std::cout << "Input: dividend = -29, divisor = -3 -> Output: " << sol.divide(-29, -3) << " (Expected: 9)\n";

    // Test 10: Divisor larger than dividend (positive)
    std::cout << "Input: dividend = 3, divisor = 10 -> Output: " << sol.divide(3, 10) << " (Expected: 0)\n";

    // Test 11: Divisor larger than dividend (negative)
    std::cout << "Input: dividend = -3, divisor = 10 -> Output: " << sol.divide(-3, 10) << " (Expected: 0)\n";

    return 0;
}
