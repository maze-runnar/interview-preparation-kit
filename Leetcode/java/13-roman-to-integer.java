import java.util.HashMap;
import java.util.Map;

class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> romanValues = new HashMap<>();
        romanValues.put('I', 1);
        romanValues.put('V', 5);
        romanValues.put('X', 10);
        romanValues.put('L', 50);
        romanValues.put('C', 100);
        romanValues.put('D', 500);
        romanValues.put('M', 1000);

        int total = 0;
        int prevValue = 0;

        // Iterate from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            int currentValue = romanValues.get(s.charAt(i));

            if (currentValue < prevValue) {
                total -= currentValue;
            } else {
                total += currentValue;
            }
            prevValue = currentValue;
        }

        return total;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Roman to Integer:");

        System.out.println("\"III\" -> " + sol.romanToInt("III") + " (Expected: 3)");
        System.out.println("\"LVIII\" -> " + sol.romanToInt("LVIII") + " (Expected: 58)");
        System.out.println("\"MCMXCIV\" -> " + sol.romanToInt("MCMXCIV") + " (Expected: 1994)");
        System.out.println("\"IX\" -> " + sol.romanToInt("IX") + " (Expected: 9)");
        System.out.println("\"IV\" -> " + sol.romanToInt("IV") + " (Expected: 4)");
        System.out.println("\"I\" -> " + sol.romanToInt("I") + " (Expected: 1)");
        System.out.println("\"MMMCMXCIX\" -> " + sol.romanToInt("MMMCMXCIX") + " (Expected: 3999)");
    }
}
