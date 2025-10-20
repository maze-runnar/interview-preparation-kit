/*
Problem 19: Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
- The number of nodes in the list is sz.
- 1 <= sz <= 30
- 0 <= Node.val <= 100
- 1 <= n <= sz
*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Approach 1: Two Pass Algorithm
    ListNode* removeNthFromEndTwoPass(ListNode* head, int n) {
        if (!head) return nullptr;

        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }

        if (length == n) { // Remove the head
            ListNode* new_head = head->next;
            delete head;
            return new_head;
        }

        current = head;
        for (int i = 0; i < length - n - 1; ++i) {
            current = current->next;
        }
        
        ListNode* node_to_delete = current->next;
        current->next = current->next->next;
        delete node_to_delete;

        return head;
    }

    // Approach 2: One Pass Algorithm using Two Pointers
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;

        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Move both pointers until first reaches the end
        while (first) {
            first = first->next;
            second = second->next;
        }

        // second is now at the node just before the one to be removed
        ListNode* node_to_delete = second->next;
        second->next = second->next->next;
        delete node_to_delete;

        return dummy.next;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    ListNode* current = head;
    std::cout << "[";
    while (current) {
        std::cout << current->val;
        if (current->next) {
            std::cout << ",";
        }
        current = current->next;
    }
    std::cout << "]\n";
}

// Helper function to create a list from a vector
ListNode* createList(const std::vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to delete a list
void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        ListNode* next_node = current->next;
        delete current;
        current = next_node;
    }
}

int main() {
    Solution sol;

    std::cout << "Testing Remove Nth Node From End of List:\n";

    // Test 1
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1);
    std::cout << "Input: "; printList(head1); std::cout << ", n = 2 -> Output: ";
    ListNode* result1 = sol.removeNthFromEnd(head1, 2);
    printList(result1);
    std::cout << " (Expected: [1,2,3,5])\n";
    deleteList(result1);

    // Test 2
    std::vector<int> arr2 = {1};
    ListNode* head2 = createList(arr2);
    std::cout << "Input: "; printList(head2); std::cout << ", n = 1 -> Output: ";
    ListNode* result2 = sol.removeNthFromEnd(head2, 1);
    printList(result2);
    std::cout << " (Expected: [])\n";
    deleteList(result2);

    // Test 3
    std::vector<int> arr3 = {1, 2};
    ListNode* head3 = createList(arr3);
    std::cout << "Input: "; printList(head3); std::cout << ", n = 1 -> Output: ";
    ListNode* result3 = sol.removeNthFromEnd(head3, 1);
    printList(result3);
    std::cout << " (Expected: [1])\n";
    deleteList(result3);

    // Test 4 (Two-pass approach specific test, though one-pass handles it)
    std::vector<int> arr4 = {1, 2, 3};
    ListNode* head4 = createList(arr4);
    std::cout << "Input: "; printList(head4); std::cout << ", n = 3 -> Output: ";
    ListNode* result4 = sol.removeNthFromEnd(head4, 3);
    printList(result4);
    std::cout << " (Expected: [2,3])\n";
    deleteList(result4);

    return 0;
}
