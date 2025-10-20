/*
Problem 2011: Final Value of Variable After Performing Operations
https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

There is a programming language with only four operations and one variable X:

--X: Decrements the value of the variable X by 1.
++X: Increments the value of the variable X by 1.
X--: Decrements the value of the variable X by 1.
X++: Increments the value of the variable X by 1.

Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

Example 1:
Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented to -1.
X++: X is incremented to 0.
X++: X is incremented to 1.
So, the final value of X is 1.

Example 2:
Input: operations = ["++X","++X","X++"]
Output: 3

Example 3:
Input: operations = ["X++","++X","--X","X--"]
Output: 0

Constraints:
- 1 <= operations.length <= 100
- operations[i] will be either "++X", "X++", "--X", or "X--".
*/

#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    int finalValueAfterOperations(std::vector<std::string>& operations) {
        int x = 0;
        for (const std::string& op : operations) {
            if (op == "++X" || op == "X++") {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }
};

int main() {
    Solution sol;

    std::vector<std::string> ops1 = {"--X","X++","X++"};
    std::cout << "Input: [\"--X\",\"X++\",\"X++\"] -> Output: " << sol.finalValueAfterOperations(ops1) << " (Expected: 1)\n";

    std::vector<std::string> ops2 = {"++X","++X","X++"};
    std::cout << "Input: [\"++X\",\"++X\",\"X++\"] -> Output: " << sol.finalValueAfterOperations(ops2) << " (Expected: 3)\n";

    std::vector<std::string> ops3 = {"X++","++X","--X","X--"};
    std::cout << "Input: [\"X++\",\"++X\",\"--X\",\"X--\"] -> Output: " << sol.finalValueAfterOperations(ops3) << " (Expected: 0)\n";

    return 0;
}
