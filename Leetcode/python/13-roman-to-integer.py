class Solution:
    def romanToInt(self, s: str) -> int:
        roman_values = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        total = 0
        prev_value = 0

        # Iterate from right to left
        for i in range(len(s) - 1, -1, -1):
            current_value = roman_values[s[i]]

            if current_value < prev_value:
                total -= current_value
            else:
                total += current_value
            prev_value = current_value

        return total

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Roman to Integer:")

    print(f"\"III\" -> {sol.romanToInt("III")} (Expected: 3)")
    print(f"\"LVIII\" -> {sol.romanToInt("LVIII")} (Expected: 58)")
    print(f"\"MCMXCIV\" -> {sol.romanToInt("MCMXCIV")} (Expected: 1994)")
    print(f"\"IX\" -> {sol.romanToInt("IX")} (Expected: 9)")
    print(f"\"IV\" -> {sol.romanToInt("IV")} (Expected: 4)")
    print(f"\"I\" -> {sol.romanToInt("I")} (Expected: 1)")
    print(f"\"MMMCMXCIX\" -> {sol.romanToInt("MMMCMXCIX")} (Expected: 3999)")
