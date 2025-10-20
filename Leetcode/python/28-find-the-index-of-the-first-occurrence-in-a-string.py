class Solution:
    # Approach 1: Built-in function (str.find)
    def strStrBuiltIn(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)

    # Approach 2: Slicing (Naive approach)
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle: 
            return 0
        if not haystack:
            return -1

        n = len(haystack)
        m = len(needle)

        for i in range(n - m + 1):
            if haystack[i:i+m] == needle:
                return i
        
        return -1

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Find the Index of the First Occurrence in a String (Naive):\n")

    # Test 1
    haystack1 = "sadbutsad"
    needle1 = "sad"
    print(f"Input: haystack = \"{haystack1}\", needle = \"{needle1}\" -> Output: {sol.strStr(haystack1, needle1)} (Expected: 0)")

    # Test 2
    haystack2 = "leetcode"
    needle2 = "leeto"
    print(f"Input: haystack = \"{haystack2}\", needle = \"{needle2}\" -> Output: {sol.strStr(haystack2, needle2)} (Expected: -1)")

    # Test 3
    haystack3 = "hello"
    needle3 = "ll"
    print(f"Input: haystack = \"{haystack3}\", needle = \"{needle3}\" -> Output: {sol.strStr(haystack3, needle3)} (Expected: 2)")

    # Test 4
    haystack4 = "aaaaa"
    needle4 = "bba"
    print(f"Input: haystack = \"{haystack4}\", needle = \"{needle4}\" -> Output: {sol.strStr(haystack4, needle4)} (Expected: -1)")

    # Test 5
    haystack5 = ""
    needle5 = "a"
    print(f"Input: haystack = \"{haystack5}\", needle = \"{needle5}\" -> Output: {sol.strStr(haystack5, needle5)} (Expected: -1)")

    # Test 6
    haystack6 = "a"
    needle6 = ""
    print(f"Input: haystack = \"{haystack6}\", needle = \"{needle6}\" -> Output: {sol.strStr(haystack6, needle6)} (Expected: 0)")

    print("\nTesting Find the Index of the First Occurrence in a String (Built-in):\n")

    # Test 7
    haystack7 = "sadbutsad"
    needle7 = "sad"
    print(f"Input: haystack = \"{haystack7}\", needle = \"{needle7}\" -> Output: {sol.strStrBuiltIn(haystack7, needle7)} (Expected: 0)")
