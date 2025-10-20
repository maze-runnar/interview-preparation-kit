/*
Problem 20: Valid Parentheses
https://leetcode.com/problems/valid-parentheses/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Constraints:
- 1 <= s.length <= 10^4
- s consists of parentheses only '()[]{}'.
*/

#include <string>
#include <stack>
#include <iostream>
#include <map>

class Solution {
public:
    // Approach: Stack
    bool isValid(std::string s) {
        std::stack<char> st;
        std::map<char, char> mappings = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            if (mappings.count(c)) { // If it's a closing bracket
                // The stack must not be empty, and the top of the stack must be the corresponding opening bracket
                if (st.empty() || st.top() != mappings[c]) {
                    return false;
                }
                st.pop();
            } else { // It's an opening bracket
                st.push(c);
            }
        }

        // If the stack is empty, all opening brackets have been matched
        return st.empty();
    }
};

int main() {
    Solution sol;

    std::cout << "Testing Valid Parentheses:\n";

    std::cout << "\"()\" -> " << (sol.isValid("()") ? "true" : "false") << " (Expected: true)\n";
    std::cout << "\"()[]{}\" -> " << (sol.isValid("()[]{\}") ? "true" : "false") << " (Expected: true)\n";
    std::cout << "\"(]\" -> " << (sol.isValid("(]") ? "true" : "false") << " (Expected: false)\n";
    std::cout << "\"{[()]}\" -> " << (sol.isValid("{[()]}") ? "true" : "false") << " (Expected: true)\n";
    std::cout << "\"([]){}\" -> " << (sol.isValid("([]){}") ? "true" : "false") << " (Expected: true)\n";
    std::cout << "\"(())\" -> " << (sol.isValid("(())") ? "true" : "false") << " (Expected: true)\n";
    std::cout << "\"{\" -> " << (sol.isValid("{") ? "true" : "false") << " (Expected: false)\n";
    std::cout << "\"]\" -> " << (sol.isValid("]") ? "true" : "false") << " (Expected: false)\n";

    return 0;
}
