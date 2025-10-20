class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mappings = {
            ')': '(',
            '}': '{',
            ']': '['
        }

        for char in s:
            if char in mappings:  # It's a closing bracket
                top_element = stack.pop() if stack else '#'
                if mappings[char] != top_element:
                    return False
            else:  # It's an opening bracket
                stack.append(char)

        return not stack

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Valid Parentheses:")

    print(f"\"()\" -> {sol.isValid("()")}" + " (Expected: True)")
    print(f"\"()[]{}\" -> {sol.isValid("()[]{\}")}" + " (Expected: True)")
    print(f"\"(]\" -> {sol.isValid("(]")}" + " (Expected: False)")
    print(f"\"{[()]}\" -> {sol.isValid("{[()]}")}" + " (Expected: True)")
    print(f"\"([]){}\" -> {sol.isValid("([]){}")}" + " (Expected: True)")
    print(f"\"(())\" -> {sol.isValid("(())")}" + " (Expected: True)")
    print(f"\"{\" -> {sol.isValid("{")}" + " (Expected: False)")
    print(f"\"]\" -> {sol.isValid("]")}" + " (Expected: False)")
