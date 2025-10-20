import java.util.ArrayList;
import java.util.List;

class Solution {
    // Approach: Backtracking
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        backtrack(result, "", 0, 0, n);
        return result;
    }

    private void backtrack(
        List<String> result,
        String currentString,
        int openCount,
        int closeCount,
        int maxPairs
    ) {
        // Base case: If the current string length is equal to 2 * maxPairs,
        // it means we have a complete combination.
        if (currentString.length() == maxPairs * 2) {
            result.add(currentString);
            return;
        }

        // Recursive case 1: Add an opening parenthesis if we still have open parentheses to add.
        // The number of open parentheses must not exceed maxPairs.
        if (openCount < maxPairs) {
            backtrack(result, currentString + '(', openCount + 1, closeCount, maxPairs);
        }

        // Recursive case 2: Add a closing parenthesis if the number of closing parentheses
        // is less than the number of open parentheses. This ensures well-formedness.
        if (closeCount < openCount) {
            backtrack(result, currentString + ')', openCount, closeCount + 1, maxPairs);
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Generate Parentheses:");

        // Test 1
        int n1 = 3;
        List<String> result1 = sol.generateParenthesis(n1);
        System.out.println("Input: n = " + n1 + " -> Output: " + result1 + " (Expected: [((())), (()()), ()(()), (())(), ()()()])");

        // Test 2
        int n2 = 1;
        List<String> result2 = sol.generateParenthesis(n2);
        System.out.println("Input: n = " + n2 + " -> Output: " + result2 + " (Expected: [()])");

        // Test 3
        int n3 = 2;
        List<String> result3 = sol.generateParenthesis(n3);
        System.out.println("Input: n = " + n3 + " -> Output: " + result3 + " (Expected: [(()), ()()])");
    }
}
