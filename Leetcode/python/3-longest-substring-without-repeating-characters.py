class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxi =0
        for i in range(len(s)):
            count = 1
            l = []
            l.append(s[i])
            for j in range(i+1, len(s)):
                if(s[j] not in l):
                    l.append(s[j])
                    count = count + 1
                else: 
                    break
            if(count > maxi):
                maxi = count
        return maxi
                
        
