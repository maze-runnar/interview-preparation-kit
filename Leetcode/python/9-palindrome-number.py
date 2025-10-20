class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        s = str(x)
        return s == s[::-1]

    def isPalindromeMath(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        reverted_number = 0
        while x > reverted_number:
            reverted_number = reverted_number * 10 + x % 10
            x //= 10

        return x == reverted_number or x == reverted_number // 10

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Palindrome Number:")

    print(f"121: {sol.isPalindrome(121)} (Expected: True)")
    print(f"-121: {sol.isPalindrome(-121)} (Expected: False)")
    print(f"10: {sol.isPalindrome(10)} (Expected: False)")
    print(f"0: {sol.isPalindrome(0)} (Expected: True)")
    print(f"12321: {sol.isPalindrome(12321)} (Expected: True)")
    print(f"123321: {sol.isPalindrome(123321)} (Expected: True)")
    print(f"12345: {sol.isPalindrome(12345)} (Expected: False)")

    print("\nTesting Palindrome Number (Math Approach):")

    print(f"121: {sol.isPalindromeMath(121)} (Expected: True)")
    print(f"-121: {sol.isPalindromeMath(-121)} (Expected: False)")
    print(f"10: {sol.isPalindromeMath(10)} (Expected: False)")
    print(f"0: {sol.isPalindromeMath(0)} (Expected: True)")
    print(f"12321: {sol.isPalindromeMath(12321)} (Expected: True)")
    print(f"123321: {sol.isPalindromeMath(123321)} (Expected: True)")
    print(f"12345: {sol.isPalindromeMath(12345)} (Expected: False)")
