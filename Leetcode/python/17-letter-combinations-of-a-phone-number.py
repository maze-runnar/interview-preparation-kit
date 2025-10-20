class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        result = []
        if not digits:
            return result

        phone_map = {
            '2': "abc",
            '3': "def",
            '4': "ghi",
            '5': "jkl",
            '6': "mno",
            '7': "pqrs",
            '8': "tuv",
            '9': "wxyz"
        }

        def backtrack(index, current_combination):
            if index == len(digits):
                result.append(current_combination)
                return

            digit = digits[index]
            letters = phone_map[digit]

            for letter in letters:
                backtrack(index + 1, current_combination + letter)

        backtrack(0, "")
        return result

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Letter Combinations of a Phone Number:")

    digits1 = "23"
    print(f"Input: \"{digits1}\" -> Output: {sol.letterCombinations(digits1)} (Expected: [\"ad\",\"ae\",\"af\",\"bd\",\"be\",\"bf\",\"cd\",\"ce\",\"cf\"])")

    digits2 = ""
    print(f"Input: \"{digits2}\" -> Output: {sol.letterCombinations(digits2)} (Expected: [])")

    digits3 = "2"
    print(f"Input: \"{digits3}\" -> Output: {sol.letterCombinations(digits3)} (Expected: [\"a\",\"b\",\"c\"])")

    digits4 = "79"
    print(f"Input: \"{digits4}\" -> Output: {sol.letterCombinations(digits4)} (Expected: [\"pw\",\"px\",\"py\",\"pz\",\"qw\",\"qx\",\"qy\",\"qz\",\"rw\",\"rx\",\"ry\",\"rz\",\"sw\",\"sx\",\"sy\",\"sz\"])")
