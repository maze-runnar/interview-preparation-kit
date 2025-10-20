class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        String s = String.valueOf(x);
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        return s.equals(sb.toString());
    }

    public boolean isPalindromeMath(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber / 10;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Palindrome Number:");

        System.out.println("121: " + (sol.isPalindrome(121) ? "true" : "false") + " (Expected: true)");
        System.out.println("-121: " + (sol.isPalindrome(-121) ? "true" : "false") + " (Expected: false)");
        System.out.println("10: " + (sol.isPalindrome(10) ? "true" : "false") + " (Expected: false)");
        System.out.println("0: " + (sol.isPalindrome(0) ? "true" : "false") + " (Expected: true)");
        System.out.println("12321: " + (sol.isPalindrome(12321) ? "true" : "false") + " (Expected: true)");
        System.out.println("123321: " + (sol.isPalindrome(123321) ? "true" : "false") + " (Expected: true)");
        System.out.println("12345: " + (sol.isPalindrome(12345) ? "true" : "false") + " (Expected: false)");

        System.out.println("\nTesting Palindrome Number (Math Approach):");

        System.out.println("121: " + (sol.isPalindromeMath(121) ? "true" : "false") + " (Expected: true)");
        System.out.println("-121: " + (sol.isPalindromeMath(-121) ? "true" : "false") + " (Expected: false)");
        System.out.println("10: " + (sol.isPalindromeMath(10) ? "true" : "false") + " (Expected: false)");
        System.out.println("0: " + (sol.isPalindromeMath(0) ? "true" : "false") + " (Expected: true)");
        System.out.println("12321: " + (sol.isPalindromeMath(12321) ? "true" : "false") + " (Expected: true)");
        System.out.println("123321: " + (sol.isPalindromeMath(123321) ? "true" : "false") + " (Expected: true)");
        System.out.println("12345: " + (sol.isPalindromeMath(12345) ? "true" : "false") + " (Expected: false)");
    }
}
