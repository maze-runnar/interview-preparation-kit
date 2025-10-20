class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        result = []

        def backtrack(current_string, open_count, close_count):
            # Base case: If the current string length is equal to 2 * n,
            # it means we have a complete combination.
            if len(current_string) == n * 2:
                result.append(current_string)
                return

            # Recursive case 1: Add an opening parenthesis if we still have open parentheses to add.
            # The number of open parentheses must not exceed n.
            if open_count < n:
                backtrack(current_string + "(", open_count + 1, close_count)
            
            # Recursive case 2: Add a closing parenthesis if the number of closing parentheses
            # is less than the number of open parentheses. This ensures well-formedness.
            if close_count < open_count:
                backtrack(current_string + ")", open_count, close_count + 1)

        backtrack("", 0, 0)
        return result

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Generate Parentheses:")

    # Test 1
    n1 = 3
    result1 = sol.generateParenthesis(n1)
    print(f"Input: n = {n1} -> Output: {result1}") # Expected: ['((()))', '(()())', '(())()', '()(())', '()()()']

    # Test 2
    n2 = 1
    result2 = sol.generateParenthesis(n2)
    print(f"Input: n = {n2} -> Output: {result2}") # Expected: ['()']

    # Test 3
    n3 = 2
    result3 = sol.generateParenthesis(n3)
    print(f"Input: n = {n3} -> Output: {result3}") # Expected: ['(())', '()()']
