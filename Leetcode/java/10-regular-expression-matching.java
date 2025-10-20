class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length();
        int n = p.length();

        boolean[][] dp = new boolean[m + 1][n + 1];

        // Empty string matches empty pattern
        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c*
        for (int j = 1; j <= n; j++) {
            if (p.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p.charAt(j - 1) == s.charAt(i - 1) || p.charAt(j - 1) == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p.charAt(j - 1) == '*') {
                    dp[i][j] = dp[i][j - 2]; // Zero occurrences of the preceding element
                    if (p.charAt(j - 2) == s.charAt(i - 1) || p.charAt(j - 2) == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // One or more occurrences
                    }
                }
            }
        }

        return dp[m][n];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Regular Expression Matching:");

        System.out.println("s = \"aa\", p = \"a\" -> " + sol.isMatch("aa", "a") + " (Expected: false)");
        System.out.println("s = \"aa\", p = \"a*\" -> " + sol.isMatch("aa", "a*") + " (Expected: true)");
        System.out.println("s = \"ab\", p = \".*\" -> " + sol.isMatch("ab", ".*") + " (Expected: true)");
        System.out.println("s = \"aab\", p = \"c*a*b\" -> " + sol.isMatch("aab", "c*a*b") + " (Expected: true)");
        System.out.println("s = \"mississippi\", p = \"mis*is*p*.\" -> " + sol.isMatch("mississippi", "mis*is*p*.") + " (Expected: false)");
        System.out.println("s = \"ab\", p = \".*c\" -> " + sol.isMatch("ab", ".*c") + " (Expected: false)");
        System.out.println("s = \"aaa\", p = \"a*a\" -> " + sol.isMatch("aaa", "a*a") + " (Expected: true)");
        System.out.println("s = \"aaa\", p = \"ab*a*c*a\" -> " + sol.isMatch("aaa", "ab*a*c*a") + " (Expected: true)");
        System.out.println("s = \"a\", p = \"ab*\" -> " + sol.isMatch("a", "ab*") + " (Expected: true)");
    }
}
