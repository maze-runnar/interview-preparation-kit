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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;
        if (list2 == null) return list1;

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                tail.next = list1;
                list1 = list1.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
            }
            tail = tail.next;
        }

        if (list1 != null) {
            tail.next = list1;
        } else if (list2 != null) {
            tail.next = list2;
        }

        return dummy.next;
    }

    // Approach 2: Recursive
    public ListNode mergeTwoListsRecursive(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;
        if (list2 == null) return list1;

        if (list1.val <= list2.val) {
            list1.next = mergeTwoListsRecursive(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeTwoListsRecursive(list1, list2.next);
            return list2;
        }
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

        System.out.println("Testing Merge Two Sorted Lists (Iterative):");

        // Test 1
        int[] arr1_1 = {1, 2, 4};
        int[] arr2_1 = {1, 3, 4};
        ListNode head1_1 = createList(arr1_1);
        ListNode head2_1 = createList(arr2_1);
        System.out.print("Input: list1 = "); printList(head1_1); System.out.print(", list2 = "); printList(head2_1); System.out.print(" -> Output: ");
        ListNode result1 = sol.mergeTwoLists(head1_1, head2_1);
        printList(result1); // Expected: [1,1,2,3,4,4]

        // Test 2
        int[] arr1_2 = {};
        int[] arr2_2 = {};
        ListNode head1_2 = createList(arr1_2);
        ListNode head2_2 = createList(arr2_2);
        System.out.print("Input: list1 = "); printList(head1_2); System.out.print(", list2 = "); printList(head2_2); System.out.print(" -> Output: ");
        ListNode result2 = sol.mergeTwoLists(head1_2, head2_2);
        printList(result2); // Expected: []

        // Test 3
        int[] arr1_3 = {};
        int[] arr2_3 = {0};
        ListNode head1_3 = createList(arr1_3);
        ListNode head2_3 = createList(arr2_3);
        System.out.print("Input: list1 = "); printList(head1_3); System.out.print(", list2 = "); printList(head2_3); System.out.print(" -> Output: ");
        ListNode result3 = sol.mergeTwoLists(head1_3, head2_3);
        printList(result3); // Expected: [0]

        System.out.println("\nTesting Merge Two Sorted Lists (Recursive):");

        // Test 4
        int[] arr1_4 = {1, 2, 4};
        int[] arr2_4 = {1, 3, 4};
        ListNode head1_4 = createList(arr1_4);
        ListNode head2_4 = createList(arr2_4);
        System.out.print("Input: list1 = "); printList(head1_4); System.out.print(", list2 = "); printList(head2_4); System.out.print(" -> Output: ");
        ListNode result4 = sol.mergeTwoListsRecursive(head1_4, head2_4);
        printList(result4); // Expected: [1,1,2,3,4,4]

        // Test 5
        int[] arr1_5 = {};
        int[] arr2_5 = {};
        ListNode head1_5 = createList(arr1_5);
        ListNode head2_5 = createList(arr2_5);
        System.out.print("Input: list1 = "); printList(head1_5); System.out.print(", list2 = "); printList(head2_5); System.out.print(" -> Output: ");
        ListNode result5 = sol.mergeTwoListsRecursive(head1_5, head2_5);
        printList(result5); // Expected: []
    }
}

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
