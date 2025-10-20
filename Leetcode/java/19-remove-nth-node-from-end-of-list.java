// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    // Approach 1: Two Pass Algorithm
    public ListNode removeNthFromEndTwoPass(ListNode head, int n) {
        if (head == null) return null;

        int length = 0;
        ListNode current = head;
        while (current != null) {
            length++;
            current = current.next;
        }

        if (length == n) { // Remove the head
            ListNode newHead = head.next;
            head = null; // Java's garbage collector will handle memory
            return newHead;
        }

        current = head;
        for (int i = 0; i < length - n - 1; i++) {
            current = current.next;
        }
        
        ListNode nodeToDelete = current.next;
        current.next = current.next.next;
        nodeToDelete = null; // Java's garbage collector will handle memory

        return head;
    }

    // Approach 2: One Pass Algorithm using Two Pointers
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) return null;

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;

        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first.next;
        }

        // Move both pointers until first reaches the end
        while (first != null) {
            first = first.next;
            second = second.next;
        }

        // second is now at the node just before the one to be removed
        ListNode nodeToDelete = second.next;
        second.next = second.next.next;
        nodeToDelete = null; // Java's garbage collector will handle memory

        return dummy.next;
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

        System.out.println("Testing Remove Nth Node From End of List:");

        // Test 1
        int[] arr1 = {1, 2, 3, 4, 5};
        ListNode head1 = createList(arr1);
        System.out.print("Input: "); printList(head1); System.out.print(", n = 2 -> Output: ");
        ListNode result1 = sol.removeNthFromEnd(head1, 2);
        printList(result1); // Expected: [1,2,3,5]
        // No explicit delete for Java, garbage collector handles it

        // Test 2
        int[] arr2 = {1};
        ListNode head2 = createList(arr2);
        System.out.print("Input: "); printList(head2); System.out.print(", n = 1 -> Output: ");
        ListNode result2 = sol.removeNthFromEnd(head2, 1);
        printList(result2); // Expected: []

        // Test 3
        int[] arr3 = {1, 2};
        ListNode head3 = createList(arr3);
        System.out.print("Input: "); printList(head3); System.out.print(", n = 1 -> Output: ");
        ListNode result3 = sol.removeNthFromEnd(head3, 1);
        printList(result3); // Expected: [1]

        // Test 4
        int[] arr4 = {1, 2, 3};
        ListNode head4 = createList(arr4);
        System.out.print("Input: "); printList(head4); System.out.print(", n = 3 -> Output: ");
        ListNode result4 = sol.removeNthFromEnd(head4, 3);
        printList(result4); // Expected: [2,3]
    }
}
