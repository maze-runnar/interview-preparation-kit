class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # Handle edge cases for overflow
        if dividend == -2**31 and divisor == -1:
            return 2**31 - 1
        
        # Determine the sign of the result
        negative = (dividend < 0) != (divisor < 0)
        
        # Convert to positive long to handle absolute values of -2**31 without overflow
        ldividend = abs(dividend)
        ldivisor = abs(divisor)
        
        quotient = 0
        
        # Repeatedly subtract divisor from dividend
        while ldividend >= ldivisor:
            temp_divisor = ldivisor
            multiple = 1
            # Find the largest multiple of divisor that is less than or equal to dividend
            while ldividend >= (temp_divisor << 1):
                temp_divisor <<= 1
                multiple <<= 1
            ldividend -= temp_divisor
            quotient += multiple
            
        # Apply the sign
        if negative:
            return -quotient
        else:
            return quotient

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Divide Two Integers:\n")

    # Test 1
    print(f"Input: dividend = 10, divisor = 3 -> Output: {sol.divide(10, 3)} (Expected: 3)")

    # Test 2
    print(f"Input: dividend = 7, divisor = -3 -> Output: {sol.divide(7, -3)} (Expected: -2)")

    # Test 3
    print(f"Input: dividend = 0, divisor = 1 -> Output: {sol.divide(0, 1)} (Expected: 0)")

    # Test 4: Edge case - dividend is -2**31, divisor is -1
    print(f"Input: dividend = -2**31, divisor = -1 -> Output: {sol.divide(-2**31, -1)} (Expected: {2**31 - 1})")

    # Test 5: Edge case - dividend is -2**31, divisor is 1
    print(f"Input: dividend = -2**31, divisor = 1 -> Output: {sol.divide(-2**31, 1)} (Expected: {-2**31})")

    # Test 6: Standard positive division
    print(f"Input: dividend = 100, divisor = 5 -> Output: {sol.divide(100, 5)} (Expected: 20)")

    # Test 7: Negative dividend, positive divisor
    print(f"Input: dividend = -29, divisor = 3 -> Output: {sol.divide(-29, 3)} (Expected: -9)")

    # Test 8: Positive dividend, negative divisor
    print(f"Input: dividend = 29, divisor = -3 -> Output: {sol.divide(29, -3)} (Expected: -9)")

    # Test 9: Both negative
    print(f"Input: dividend = -29, divisor = -3 -> Output: {sol.divide(-29, -3)} (Expected: 9)")

    # Test 10: Divisor larger than dividend (positive)
    print(f"Input: dividend = 3, divisor = 10 -> Output: {sol.divide(3, 10)} (Expected: 0)")

    # Test 11: Divisor larger than dividend (negative)
    print(f"Input: dividend = -3, divisor = 10 -> Output: {sol.divide(-3, 10)} (Expected: 0)")
