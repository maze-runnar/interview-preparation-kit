import java.util.Stack;
import java.util.HashMap;
import java.util.Map;

class Solution {
    // Approach: Stack
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        Map<Character, Character> mappings = new HashMap<>();
        mappings.put(')', '(');
        mappings.put('}', '{');
        mappings.put(']', '[');

        for (char c : s.toCharArray()) {
            if (mappings.containsKey(c)) { // If it's a closing bracket
                // The stack must not be empty, and the top of the stack must be the corresponding opening bracket
                char topElement = st.empty() ? '#' : st.pop();
                if (topElement != mappings.get(c)) {
                    return false;
                }
            } else { // It's an opening bracket
                st.push(c);
            }
        }

        // If the stack is empty, all opening brackets have been matched
        return st.empty();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Valid Parentheses:");

        System.out.println("\"()\" -> " + sol.isValid("()") + " (Expected: true)");
        System.out.println("\"()[]{}\" -> " + sol.isValid("()[]{\}") + " (Expected: true)");
        System.out.println("\"(]\" -> " + sol.isValid("(]") + " (Expected: false)");
        System.out.println("\"{[()]}\" -> " + sol.isValid("{[()]}") + " (Expected: true)");
        System.out.println("\"([]){}\" -> " + sol.isValid("([]){}") + " (Expected: true)");
        System.out.println("\"(())\" -> " + sol.isValid("(())") + " (Expected: true)");
        System.out.println("\"{\" -> " + sol.isValid("{") + " (Expected: false)");
        System.out.println("\"]\" -> " + sol.isValid("]") + " (Expected: false)");
    }
}
