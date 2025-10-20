import java.util.HashMap;
import java.util.Map;

class Solution {
    public String intToRoman(int num) {
        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < values.length; i++) {
            while (num >= values[i]) {
                result.append(symbols[i]);
                num -= values[i];
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Integer to Roman:");

        System.out.println("3 -> " + sol.intToRoman(3) + " (Expected: III)");
        System.out.println("58 -> " + sol.intToRoman(58) + " (Expected: LVIII)");
        System.out.println("1994 -> " + sol.intToRoman(1994) + " (Expected: MCMXCIV)");
        System.out.println("9 -> " + sol.intToRoman(9) + " (Expected: IX)");
        System.out.println("4 -> " + sol.intToRoman(4) + " (Expected: IV)");
        System.out.println("1 -> " + sol.intToRoman(1) + " (Expected: I)");
        System.out.println("3999 -> " + sol.intToRoman(3999) + " (Expected: MMMCMXCIX)");
    }
}
