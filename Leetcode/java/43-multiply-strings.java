/*
43. Multiply Strings
Medium - 42.9%

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
*/

class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";
        
        int m = num1.length(), n = num2.length();
        int[] result = new int[m + n];
        
        // Multiply each digit from right to left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                int pos1 = i + j, pos2 = i + j + 1;
                int sum = mul + result[pos2];
                
                result[pos2] = sum % 10;
                result[pos1] += sum / 10;
            }
        }
        
        // Convert result to string
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < result.length; i++) {
            if (!(sb.length() == 0 && result[i] == 0)) {
                sb.append(result[i]);
            }
        }
        
        return sb.length() == 0 ? "0" : sb.toString();
    }
}
