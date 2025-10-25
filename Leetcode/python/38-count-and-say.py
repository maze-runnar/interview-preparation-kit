"""
38. Count and Say
Medium - 61.6%

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
- countAndSay(1) = "1"
- countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), 
  which is then converted into a different digit string.

To determine how you "say" a digit string, read it from left to right, note the frequency 
of each digit in a row, and say it. For example, the digit string "3322251" would be said 
as "two 3s, three 2s, one 5, and one 1".

Given a positive integer n, return the nth term of the count-and-say sequence.

Example 1:
Input: n = 1
Output: "1"
Explanation: This is the base case.

Example 2:
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1s = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
"""

class Solution:
    def countAndSay(self, n: int) -> str:
        result = "1"
        
        for i in range(1, n):
            result = self.get_next(result)
        
        return result
    
    def get_next(self, s: str) -> str:
        result = ""
        i = 0
        
        while i < len(s):
            current = s[i]
            count = 1
            
            # Count consecutive same characters
            while i + 1 < len(s) and s[i + 1] == current:
                count += 1
                i += 1
            
            # Append count and character to result
            result += str(count) + current
            i += 1
        
        return result
