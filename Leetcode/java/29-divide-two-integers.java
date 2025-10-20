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

class Solution {
    public int divide(int dividend, int divisor) {
        // Handle edge cases for overflow
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE; // Overflow case: -2^31 / -1 = 2^31 which is Integer.MAX_VALUE + 1
        }

        // Determine the sign of the result
        boolean negative = (dividend < 0) != (divisor < 0);

        // Convert to long to handle absolute values of Integer.MIN_VALUE without overflow
        long ldividend = Math.abs((long) dividend);
        long ldivisor = Math.abs((long) divisor);

        long quotient = 0;

        // Repeatedly subtract divisor from dividend
        while (ldividend >= ldivisor) {
            long tempDivisor = ldivisor;
            long multiple = 1;
            // Find the largest multiple of divisor that is less than or equal to dividend
            while (ldividend >= (tempDivisor << 1) && (tempDivisor << 1) > 0) { // (tempDivisor << 1) > 0 to prevent overflow
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            ldividend -= tempDivisor;
            quotient += multiple;
        }

        // Apply the sign
        return (int) (negative ? -quotient : quotient);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Divide Two Integers:\n");

        // Test 1
        System.out.println("Input: dividend = 10, divisor = 3 -> Output: " + sol.divide(10, 3) + " (Expected: 3)");

        // Test 2
        System.out.println("Input: dividend = 7, divisor = -3 -> Output: " + sol.divide(7, -3) + " (Expected: -2)");

        // Test 3
        System.out.println("Input: dividend = 0, divisor = 1 -> Output: " + sol.divide(0, 1) + " (Expected: 0)");

        // Test 4: Edge case - dividend is Integer.MIN_VALUE, divisor is -1
        System.out.println("Input: dividend = " + Integer.MIN_VALUE + ", divisor = -1 -> Output: " + sol.divide(Integer.MIN_VALUE, -1) + " (Expected: " + Integer.MAX_VALUE + ")");

        // Test 5: Edge case - dividend is Integer.MIN_VALUE, divisor is 1
        System.out.println("Input: dividend = " + Integer.MIN_VALUE + ", divisor = 1 -> Output: " + sol.divide(Integer.MIN_VALUE, 1) + " (Expected: " + Integer.MIN_VALUE + ")");

        // Test 6: Standard positive division
        System.out.println("Input: dividend = 100, divisor = 5 -> Output: " + sol.divide(100, 5) + " (Expected: 20)");

        // Test 7: Negative dividend, positive divisor
        System.out.println("Input: dividend = -29, divisor = 3 -> Output: " + sol.divide(-29, 3) + " (Expected: -9)");

        // Test 8: Positive dividend, negative divisor
        System.out.println("Input: dividend = 29, divisor = -3 -> Output: " + sol.divide(29, -3) + " (Expected: -9)");

        // Test 9: Both negative
        System.out.println("Input: dividend = -29, divisor = -3 -> Output: " + sol.divide(-29, -3) + " (Expected: 9)");

        // Test 10: Divisor larger than dividend (positive)
        System.out.println("Input: dividend = 3, divisor = 10 -> Output: " + sol.divide(3, 10) + " (Expected: 0)");

        // Test 11: Divisor larger than dividend (negative)
        System.out.println("Input: dividend = -3, divisor = 10 -> Output: " + sol.divide(-3, 10) + " (Expected: 0)");
    }
}
