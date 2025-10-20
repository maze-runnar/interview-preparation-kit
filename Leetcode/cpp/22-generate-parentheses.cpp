/*
Problem 22: Generate Parentheses
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
- 1 <= n <= 8
*/

#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    // Approach: Backtracking
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(
        std::vector<std::string>& result,
        std::string current_string,
        int open_count,
        int close_count,
        int max_pairs
    ) {
        // Base case: If the current string length is equal to 2 * max_pairs,
        // it means we have a complete combination.
        if (current_string.length() == max_pairs * 2) {
            result.push_back(current_string);
            return;
        }

        // Recursive case 1: Add an opening parenthesis if we still have open parentheses to add.
        // The number of open parentheses must not exceed max_pairs.
        if (open_count < max_pairs) {
            backtrack(result, current_string + '(', open_count + 1, close_count, max_pairs);
        }

        // Recursive case 2: Add a closing parenthesis if the number of closing parentheses
        // is less than the number of open parentheses. This ensures well-formedness.
        if (close_count < open_count) {
            backtrack(result, current_string + ')', open_count, close_count + 1, max_pairs);
        }
    }
};

int main() {
    Solution sol;

    std::cout << "Testing Generate Parentheses:\n";

    // Test 1
    int n1 = 3;
    std::vector<std::string> result1 = sol.generateParenthesis(n1);
    std::cout << "Input: n = " << n1 << " -> Output: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        std::cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: [\"((()))\",\"(()())\",\"(())()\",\"()(())\",\"()()()\"])\n";

    // Test 2
    int n2 = 1;
    std::vector<std::string> result2 = sol.generateParenthesis(n2);
    std::cout << "Input: n = " << n2 << " -> Output: [";
    for (size_t i = 0; i < result2.size(); ++i) {
        std::cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: [\"()\"])\n";

    // Test 3
    int n3 = 2;
    std::vector<std::string> result3 = sol.generateParenthesis(n3);
    std::cout << "Input: n = " << n3 << " -> Output: [";
    for (size_t i = 0; i < result3.size(); ++i) {
        std::cout << "\"" << result3[i] << "\"";
        if (i < result3.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "] (Expected: [\"(())\",\"()()\"])\n";

    return 0;
}
