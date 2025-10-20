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
    // Approach 1: Iterative (without a stack - direct reversal)
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k == 1) {
            return head;
        }

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode curr = head;

        while (curr != null) {
            ListNode tail = curr;
            int count = 0;
            // Check if there are k nodes remaining in the current group
            while (tail != null && count < k) {
                tail = tail.next;
                count++;
            }

            if (count == k) { // If k nodes are available
                // Reverse the current k-group
                ListNode subPrev = null;
                ListNode subCurr = curr;
                for (int i = 0; i < k; ++i) {
                    ListNode nextNode = subCurr.next;
                    subCurr.next = subPrev;
                    subPrev = subCurr;
                    subCurr = nextNode;
                }

                // Connect the reversed group
                prev.next = subPrev; // prev points to the new head of the reversed group
                curr.next = subCurr; // current (old head) points to the next group's head

                prev = curr; // Move prev to the tail of the current reversed group
                curr = subCurr; // Move curr to the head of the next group
            } else { // Less than k nodes, append them as they are and stop
                prev.next = curr;
                break;
            }
        }

        return dummy.next;
    }

    // Approach 2: Recursive
    public ListNode reverseKGroupRecursive(ListNode head, int k) {
        ListNode current = head;
        int count = 0;
        // Check if there are at least k nodes remaining
        while (current != null && count < k) {
            current = current.next;
            count++;
        }
        
        // If we have k nodes, then reverse them
        if (count == k) {
            current = reverseKGroupRecursive(current, k);  // Recursively reverse the next k-group
            
            // Reverse the current k nodes
            for (int i = 0; i < k; i++) {
                ListNode temp = head.next;
                head.next = current;
                current = head;
                head = temp;
            }
            head = current; // The new head of this reversed group is 'current'
        }
        
        return head;
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

        System.out.println("Testing Reverse Nodes in k-Group (Iterative):\n");

        // Test 1
        ListNode head1_1 = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Input: [1,2,3,4,5], k = 2 -> Output: ");
        ListNode result1_1 = sol.reverseKGroup(head1_1, 2);
        printList(result1_1); // Expected: [2,1,4,3,5]

        // Test 2
        ListNode head1_2 = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Input: [1,2,3,4,5], k = 3 -> Output: ");
        ListNode result1_2 = sol.reverseKGroup(head1_2, 3);
        printList(result1_2); // Expected: [3,2,1,4,5]

        // Test 3
        ListNode head1_3 = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Input: [1,2,3,4,5], k = 1 -> Output: ");
        ListNode result1_3 = sol.reverseKGroup(head1_3, 1);
        printList(result1_3); // Expected: [1,2,3,4,5]

        // Test 4
        ListNode head1_4 = createList(new int[]{1, 2, 3});
        System.out.print("Input: [1,2,3], k = 4 -> Output: ");
        ListNode result1_4 = sol.reverseKGroup(head1_4, 4);
        printList(result1_4); // Expected: [1,2,3]

        System.out.println("\nTesting Reverse Nodes in k-Group (Recursive):\n");

        // Test 5
        ListNode head2_1 = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Input: [1,2,3,4,5], k = 2 -> Output: ");
        ListNode result2_1 = sol.reverseKGroupRecursive(head2_1, 2);
        printList(result2_1); // Expected: [2,1,4,3,5]

        // Test 6
        ListNode head2_2 = createList(new int[]{1, 2, 3, 4, 5});
        System.out.print("Input: [1,2,3,4,5], k = 3 -> Output: ");
        ListNode result2_2 = sol.reverseKGroupRecursive(head2_2, 3);
        printList(result2_2); // Expected: [3,2,1,4,5]

        // Test 7
        ListNode head2_3 = createList(new int[]{1, 2, 3});
        System.out.print("Input: [1,2,3], k = 4 -> Output: ");
        ListNode result2_3 = sol.reverseKGroupRecursive(head2_3, 4);
        printList(result2_3); // Expected: [1,2,3]
    }
}
