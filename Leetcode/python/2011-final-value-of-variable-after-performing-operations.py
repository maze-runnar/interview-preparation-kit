class Solution:
    def finalValueAfterOperations(self, operations: list[str]) -> int:
        x = 0
        for op in operations:
            if op == "++X" or op == "X++":
                x += 1
            else:
                x -= 1
        return x

# Test cases
if __name__ == "__main__":
    sol = Solution()

    ops1 = ["--X","X++","X++"]
    print(f"Input: {ops1} -> Output: {sol.finalValueAfterOperations(ops1)} (Expected: 1)")

    ops2 = ["++X","++X","X++"]
    print(f"Input: {ops2} -> Output: {sol.finalValueAfterOperations(ops2)} (Expected: 3)")

    ops3 = ["X++","++X","--X","X--"]
    print(f"Input: {ops3} -> Output: {sol.finalValueAfterOperations(ops3)} (Expected: 0)")
