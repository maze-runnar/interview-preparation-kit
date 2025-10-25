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

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        
        if (s.length() < totalLen) return result;
        
        // Count frequency of each word
        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }
        
        // Check each possible starting position
        for (int i = 0; i <= (int)s.length() - totalLen; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            
            // Check each word in the current window
            for (j = 0; j < wordCount; j++) {
                string word = s.substr(i + j * wordLen, wordLen);
                
                if (wordFreq.find(word) == wordFreq.end()) {
                    break; // Word not in words array
                }
                
                seen[word]++;
                if (seen[word] > wordFreq[word]) {
                    break; // Too many occurrences of this word
                }
            }
            
            // If we processed all words successfully
            if (j == wordCount) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
