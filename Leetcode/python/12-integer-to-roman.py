class Solution:
    def intToRoman(self, num: int) -> str:
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]

        result = ""

        for i in range(len(values)):
            while num >= values[i]:
                result += symbols[i]
                num -= values[i]
        
        return result

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Integer to Roman:")

    print(f"3 -> {sol.intToRoman(3)} (Expected: III)")
    print(f"58 -> {sol.intToRoman(58)} (Expected: LVIII)")
    print(f"1994 -> {sol.intToRoman(1994)} (Expected: MCMXCIV)")
    print(f"9 -> {sol.intToRoman(9)} (Expected: IX)")
    print(f"4 -> {sol.intToRoman(4)} (Expected: IV)")
    print(f"1 -> {sol.intToRoman(1)} (Expected: I)")
    print(f"3999 -> {sol.intToRoman(3999)} (Expected: MMMCMXCIX)")
