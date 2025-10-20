/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    // Approach 1: Iterative
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;

        while (prev.next != null && prev.next.next != null) {
            ListNode first = prev.next;
            ListNode second = prev.next.next;

            // Swapping
            first.next = second.next;
            second.next = first;
            prev.next = second;

            // Move to the next pair
            prev = first;
        }
        return dummy.next;
    }

    // Approach 2: Recursive
    public ListNode swapPairsRecursive(ListNode head) {
        // Base case: no node or only one node, nothing to swap
        if (head == null || head.next == null) {
            return head;
        }

        // Nodes to be swapped
        ListNode first = head;
        ListNode second = head.next;

        // Recurse for the rest of the list
        first.next = swapPairsRecursive(second.next);
        second.next = first;

        // New head of the swapped pair is 'second'
        return second;
    }

    // Helper function to print the list
    public static void printList(ListNode head) {
        ListNode current = head;
        System.out.print("[");
        while (current != null) {
            System.out.print(current.val);
            if (current.next != null) {
                System.out.print(",");
            }
            current = current.next;
        }
        System.out.println("]");
    }

    // Helper function to create a list from an array
    public static ListNode createList(int[] arr) {
        if (arr == null || arr.length == 0) {
            return null;
        }
        ListNode head = new ListNode(arr[0]);
        ListNode current = head;
        for (int i = 1; i < arr.length; i++) {
            current.next = new ListNode(arr[i]);
            current = current.next;
        }
        return head;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println("Testing Swap Nodes in Pairs (Iterative):\n");

        // Test 1
        ListNode head1 = createList(new int[]{1, 2, 3, 4});
        System.out.print("Input: [1,2,3,4] -> Output: ");
        ListNode result1 = sol.swapPairs(head1);
        printList(result1); // Expected: [2,1,4,3]

        // Test 2
        ListNode head2 = createList(new int[]{});
        System.out.print("Input: [] -> Output: ");
        ListNode result2 = sol.swapPairs(head2);
        printList(result2); // Expected: []

        // Test 3
        ListNode head3 = createList(new int[]{1});
        System.out.print("Input: [1] -> Output: ");
        ListNode result3 = sol.swapPairs(head3);
        printList(result3); // Expected: [1]

        // Test 4
        ListNode head4 = createList(new int[]{1, 2, 3});
        System.out.print("Input: [1,2,3] -> Output: ");
        ListNode result4 = sol.swapPairs(head4);
        printList(result4); // Expected: [2,1,3]

        System.out.println("\nTesting Swap Nodes in Pairs (Recursive):\n");

        // Test 5
        ListNode head5 = createList(new int[]{1, 2, 3, 4});
        System.out.print("Input: [1,2,3,4] -> Output: ");
        ListNode result5 = sol.swapPairsRecursive(head5);
        printList(result5); // Expected: [2,1,4,3]

        // Test 6
        ListNode head6 = createList(new int[]{});
        System.out.print("Input: [] -> Output: ");
        ListNode result6 = sol.swapPairsRecursive(head6);
        printList(result6); // Expected: []
    }
}
