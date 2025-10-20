class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int x = 0;
        for (String op : operations) {
            if (op.equals("++X") || op.equals("X++")) {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        String[] ops1 = {"--X","X++","X++"};
        System.out.println("Input: [\"--X\",\"X++\",\"X++\"] -> Output: " + sol.finalValueAfterOperations(ops1) + " (Expected: 1)");

        String[] ops2 = {"++X","++X","X++"};
        System.out.println("Input: [\"++X\",\"++X\",\"X++\"] -> Output: " + sol.finalValueAfterOperations(ops2) + " (Expected: 3)");

        String[] ops3 = {"X++","++X","--X","X--"};
        System.out.println("Input: [\"X++\",\"++X\",\"--X\",\"X--\"] -> Output: " + sol.finalValueAfterOperations(ops3) + " (Expected: 0)");
    }
}
