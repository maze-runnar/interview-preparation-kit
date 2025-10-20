/*
Problem 17: Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
- 0 <= digits.length <= 4
- digits[i] is a digit in the range ['2', '9'].
*/

#include <vector>
#include <string>
#include <map>
#include <iostream>

class Solution {
public:
    // Approach: Backtracking
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }

        std::map<char, std::string> phone_map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        std::string current_combination;
        backtrack(digits, 0, phone_map, current_combination, result);

        return result;
    }

private:
    void backtrack(
        const std::string& digits,
        int index,
        const std::map<char, std::string>& phone_map,
        std::string& current_combination,
        std::vector<std::string>& result
    ) {
        if (index == digits.length()) {
            result.push_back(current_combination);
            return;
        }

        char digit = digits[index];
        const std::string& letters = phone_map.at(digit);

        for (char letter : letters) {
            current_combination.push_back(letter);
            backtrack(digits, index + 1, phone_map, current_combination, result);
            current_combination.pop_back(); // Backtrack
        }
    }
};

void printResult(const std::vector<std::string>& result) {
    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]\n";
}

int main() {
    Solution sol;

    std::cout << "Testing Letter Combinations of a Phone Number:\n";

    std::string digits1 = "23";
    std::cout << "Input: \"23\" -> Output: ";
    printResult(sol.letterCombinations(digits1));
    std::cout << " (Expected: [\"ad\",\"ae\",\"af\",\"bd\",\"be\",\"bf\",\"cd\",\"ce\",\"cf\"])\n";

    std::string digits2 = "";
    std::cout << "Input: \"\" -> Output: ";
    printResult(sol.letterCombinations(digits2));
    std::cout << " (Expected: [])\n";

    std::string digits3 = "2";
    std::cout << "Input: \"2\" -> Output: ";
    printResult(sol.letterCombinations(digits3));
    std::cout << " (Expected: [\"a\",\"b\",\"c\"])\n";

    std::string digits4 = "79";
    std::cout << "Input: \"79\" -> Output: ";
    printResult(sol.letterCombinations(digits4));
    // Expected: ["pw", "px", "py", "pz", "qw", "qx", "qy", "qz", "rw", "rx", "ry", "rz", "sw", "sx", "sy", "sz"]
    std::cout << " (Expected: [\"pw\",\"px\",\"py\",\"pz\",\"qw\",\"qx\",\"qy\",\"qz\",\"rw\",\"rx\",\"ry\",\"rz\",\"sw\",\"sx\",\"sy\",\"sz\"])\n";

    return 0;
}
