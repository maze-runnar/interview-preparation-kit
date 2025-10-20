import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    // Approach: Backtracking
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if (digits == null || digits.isEmpty()) {
            return result;
        }

        Map<Character, String> phoneMap = new HashMap<>();
        phoneMap.put('2', "abc");
        phoneMap.put('3', "def");
        phoneMap.put('4', "ghi");
        phoneMap.put('5', "jkl");
        phoneMap.put('6', "mno");
        phoneMap.put('7', "pqrs");
        phoneMap.put('8', "tuv");
        phoneMap.put('9', "wxyz");

        backtrack(digits, 0, phoneMap, new StringBuilder(), result);

        return result;
    }

    private void backtrack(
        String digits,
        int index,
        Map<Character, String> phoneMap,
        StringBuilder currentCombination,
        List<String> result
    ) {
        if (index == digits.length()) {
            result.add(currentCombination.toString());
            return;
        }

        char digit = digits.charAt(index);
        String letters = phoneMap.get(digit);

        for (char letter : letters.toCharArray()) {
            currentCombination.append(letter);
            backtrack(digits, index + 1, phoneMap, currentCombination, result);
            currentCombination.deleteCharAt(currentCombination.length() - 1); // Backtrack
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Letter Combinations of a Phone Number:");

        String digits1 = "23";
        System.out.println("Input: \"23\" -> Output: " + sol.letterCombinations(digits1) + " (Expected: [ad, ae, af, bd, be, bf, cd, ce, cf])");

        String digits2 = "";
        System.out.println("Input: \"\" -> Output: " + sol.letterCombinations(digits2) + " (Expected: [])");

        String digits3 = "2";
        System.out.println("Input: \"2\" -> Output: " + sol.letterCombinations(digits3) + " (Expected: [a, b, c])");

        String digits4 = "79";
        System.out.println("Input: \"79\" -> Output: " + sol.letterCombinations(digits4) + " (Expected: [pw, px, py, pz, qw, qx, qy, qz, rw, rx, ry, rz, sw, sx, sy, sz])");
    }
}
