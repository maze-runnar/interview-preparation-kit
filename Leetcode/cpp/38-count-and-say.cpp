/*
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
*/

#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int i = 1; i < n; i++) {
            result = getNext(result);
        }
        
        return result;
    }
    
private:
    string getNext(const string& s) {
        string result = "";
        int i = 0;
        
        while (i < s.length()) {
            char current = s[i];
            int count = 1;
            
            // Count consecutive same characters
            while (i + 1 < s.length() && s[i + 1] == current) {
                count++;
                i++;
            }
            
            // Append count and character to result
            result += to_string(count) + current;
            i++;
        }
        
        return result;
    }
};
