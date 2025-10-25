/*
30. Substring with Concatenation of All Words
Hard - 33.5%

You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.

Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

Example 1:
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","good"]
Output: [8]
Explanation: The substring starting at 8 is "goodgoodbestword". It is the concatenation of ["good","good","best","word"] which is a permutation of words.

Example 3:
Input: s = "barfoobar", words = ["foo","bar"]
Output: [0,3,6]
*/

import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) {
            return result;
        }
        
        int wordLen = words[0].length();
        int wordCount = words.length;
        int totalLen = wordLen * wordCount;
        
        if (s.length() < totalLen) return result;
        
        // Count frequency of each word
        Map<String, Integer> wordFreq = new HashMap<>();
        for (String word : words) {
            wordFreq.put(word, wordFreq.getOrDefault(word, 0) + 1);
        }
        
        // Check each possible starting position
        for (int i = 0; i <= s.length() - totalLen; i++) {
            Map<String, Integer> seen = new HashMap<>();
            int j = 0;
            
            // Check each word in the current window
            for (j = 0; j < wordCount; j++) {
                String word = s.substring(i + j * wordLen, i + (j + 1) * wordLen);
                
                if (!wordFreq.containsKey(word)) {
                    break; // Word not in words array
                }
                
                seen.put(word, seen.getOrDefault(word, 0) + 1);
                if (seen.get(word) > wordFreq.get(word)) {
                    break; // Too many occurrences of this word
                }
            }
            
            // If we processed all words successfully
            if (j == wordCount) {
                result.add(i);
            }
        }
        
        return result;
    }
}
