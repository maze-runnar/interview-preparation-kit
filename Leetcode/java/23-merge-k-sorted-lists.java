import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Comparator;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    // Approach 1: Using a Min-Priority Queue (Heap)
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }

        // Custom comparator for the priority queue
        PriorityQueue<ListNode> pq = new PriorityQueue<>(
            new Comparator<ListNode>() {
                @Override
                public int compare(ListNode l1, ListNode l2) {
                    return l1.val - l2.val;
                }
            }
        );

        // Add the head of each list to the priority queue
        for (ListNode list : lists) {
            if (list != null) {
                pq.add(list);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (!pq.isEmpty()) {
            ListNode smallest = pq.poll();
            tail.next = smallest;
            tail = tail.next;

            if (smallest.next != null) {
                pq.add(smallest.next);
            }
        }

        return dummy.next;
    }

    // Helper function to merge two sorted lists (from Problem 21)
    private ListNode mergeTwoLists(ListNode list1, ListNode list2) {
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

    // Approach 2: Divide and Conquer
    public ListNode mergeKListsDivideConquer(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        return mergeKListsHelper(lists, 0, lists.length - 1);
    }

    private ListNode mergeKListsHelper(ListNode[] lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start > end) {
            return null;
        }

        int mid = start + (end - start) / 2;
        ListNode left = mergeKListsHelper(lists, start, mid);
        ListNode right = mergeKListsHelper(lists, mid + 1, end);
        return mergeTwoLists(left, right);
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

        System.out.println("Testing Merge K Sorted Lists (Min-Priority Queue):\n");

        // Test 1
        ListNode[] lists1 = {createList(new int[]{1, 4, 5}), createList(new int[]{1, 3, 4}), createList(new int[]{2, 6})};
        System.out.print("Input: lists = [[1,4,5],[1,3,4],[2,6]] -> Output: ");
        ListNode result1 = sol.mergeKLists(lists1);
        printList(result1); // Expected: [1,1,2,3,4,4,5,6]

        // Test 2
        ListNode[] lists2 = {};
        System.out.print("Input: lists = [] -> Output: ");
        ListNode result2 = sol.mergeKLists(lists2);
        printList(result2); // Expected: []

        // Test 3
        ListNode[] lists3 = {createList(new int[]{})};
        System.out.print("Input: lists = [[]] -> Output: ");
        ListNode result3 = sol.mergeKLists(lists3);
        printList(result3); // Expected: []

        System.out.println("\nTesting Merge K Sorted Lists (Divide and Conquer):\n");

        // Test 4
        ListNode[] lists4 = {createList(new int[]{1, 4, 5}), createList(new int[]{1, 3, 4}), createList(new int[]{2, 6})};
        System.out.print("Input: lists = [[1,4,5],[1,3,4],[2,6]] -> Output: ");
        ListNode result4 = sol.mergeKListsDivideConquer(lists4);
        printList(result4); // Expected: [1,1,2,3,4,4,5,6]

        // Test 5
        ListNode[] lists5 = {};
        System.out.print("Input: lists = [] -> Output: ");
        ListNode result5 = sol.mergeKListsDivideConquer(lists5);
        printList(result5); // Expected: []
    }
}
