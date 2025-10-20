import java.util.Arrays;

class Solution {
    // Approach 1: Horizontal scanning
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }

        String prefix = strs[0];
        for (int i = 1; i < strs.length; i++) {
            while (strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);
                if (prefix.isEmpty()) {
                    return "";
                }
            }
        }
        return prefix;
    }

    // Approach 2: Vertical scanning
    public String longestCommonPrefixVertical(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }

        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (i == strs[j].length() || strs[j].charAt(i) != c) {
                    return strs[0].substring(0, i);
                }
            }
        }
        return strs[0];
    }

    // Approach 3: Divide and Conquer
    public String longestCommonPrefixDivideConquer(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        return longestCommonPrefixRecursive(strs, 0, strs.length - 1);
    }

    private String longestCommonPrefixRecursive(String[] strs, int left, int right) {
        if (left == right) {
            return strs[left];
        }

        int mid = (left + right) / 2;
        String lcpLeft = longestCommonPrefixRecursive(strs, left, mid);
        String lcpRight = longestCommonPrefixRecursive(strs, mid + 1, right);
        return commonPrefix(lcpLeft, lcpRight);
    }

    private String commonPrefix(String str1, String str2) {
        int minLength = Math.min(str1.length(), str2.length());
        for (int i = 0; i < minLength; i++) {
            if (str1.charAt(i) != str2.charAt(i)) {
                return str1.substring(0, i);
            }
        }
        return str1.substring(0, minLength);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Longest Common Prefix (Horizontal Scanning):");
        String[] strs1 = {"flower", "flow", "flight"};
        System.out.println("Input: [\"flower\",\"flow\",\"flight\"] -> Output: \"" + sol.longestCommonPrefix(strs1) + "\" (Expected: \"fl\")");

        String[] strs2 = {"dog", "racecar", "car"};
        System.out.println("Input: [\"dog\",\"racecar\",\"car\"] -> Output: \"" + sol.longestCommonPrefix(strs2) + "\" (Expected: \"\")");

        String[] strs3 = {"apple", "apricot", "april"};
        System.out.println("Input: [\"apple\",\"apricot\",\"april\"] -> Output: \"" + sol.longestCommonPrefix(strs3) + "\" (Expected: \"ap\")");
        
        System.out.println("\nTesting Longest Common Prefix (Vertical Scanning):\n");
        String[] strs4 = {"flower", "flow", "flight"};
        System.out.println("Input: [\"flower\",\"flow\",\"flight\"] -> Output: \"" + sol.longestCommonPrefixVertical(strs4) + "\" (Expected: \"fl\")");

        String[] strs5 = {"dog", "racecar", "car"};
        System.out.println("Input: [\"dog\",\"racecar\",\"car\"] -> Output: \"" + sol.longestCommonPrefixVertical(strs5) + "\" (Expected: \"\")");

        String[] strs6 = {"apple", "apricot", "april"};
        System.out.println("Input: [\"apple\",\"apricot\",\"april\"] -> Output: \"" + sol.longestCommonPrefixVertical(strs6) + "\" (Expected: \"ap\")");

        System.out.println("\nTesting Longest Common Prefix (Divide and Conquer):\n");
        String[] strs7 = {"flower", "flow", "flight"};
        System.out.println("Input: [\"flower\",\"flow\",\"flight\"] -> Output: \"" + sol.longestCommonPrefixDivideConquer(strs7) + "\" (Expected: \"fl\")");

        String[] strs8 = {"dog", "racecar", "car"};
        System.out.println("Input: [\"dog\",\"racecar\",\"car\"] -> Output: \"" + sol.longestCommonPrefixDivideConquer(strs8) + "\" (Expected: \"\")");

        String[] strs9 = {"apple", "apricot", "april"};
        System.out.println("Input: [\"apple\",\"apricot\",\"april\"] -> Output: \"" + sol.longestCommonPrefixDivideConquer(strs9) + "\" (Expected: \"ap\")");
    }
}
