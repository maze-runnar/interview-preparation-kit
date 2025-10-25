"""
32. Longest Valid Parentheses
Hard - 37.3%

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0
"""

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]  # Base for calculation
        max_len = 0
        
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:  # s[i] == ')'
                stack.pop()
                
                if not stack:
                    # No matching '(' for current ')'
                    stack.append(i)
                else:
                    # Calculate length of current valid parentheses
                    max_len = max(max_len, i - stack[-1])
        
        return max_len
