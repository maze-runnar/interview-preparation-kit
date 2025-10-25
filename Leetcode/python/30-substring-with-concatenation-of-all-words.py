"""
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
"""

from typing import List
from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []
        
        word_len = len(words[0])
        word_count = len(words)
        total_len = word_len * word_count
        
        if len(s) < total_len:
            return []
        
        # Count frequency of each word
        word_freq = Counter(words)
        result = []
        
        # Check each possible starting position
        for i in range(len(s) - total_len + 1):
            seen = Counter()
            j = 0
            
            # Check each word in the current window
            for j in range(word_count):
                word = s[i + j * word_len:i + (j + 1) * word_len]
                
                if word not in word_freq:
                    break  # Word not in words array
                
                seen[word] += 1
                if seen[word] > word_freq[word]:
                    break  # Too many occurrences of this word
            
            # If we processed all words successfully
            if j == word_count - 1 and seen == word_freq:
                result.append(i)
        
        return result
