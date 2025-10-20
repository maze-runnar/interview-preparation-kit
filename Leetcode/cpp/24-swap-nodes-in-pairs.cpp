/*
Problem 24: Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed).

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Constraints:
- The number of nodes in the list is in the range [0, 100].
- 0 <= Node.val <= 100
*/

#include <iostream>
#include <vector>

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
    // Approach 1: Iterative
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to the next pair
            prev = first;
        }
        return dummy.next;
    }

    // Approach 2: Recursive
    ListNode* swapPairsRecursive(ListNode* head) {
        // Base case: no node or only one node, nothing to swap
        if (!head || !head->next) {
            return head;
        }

        // Nodes to be swapped
        ListNode* first = head;
        ListNode* second = head->next;

        // Recurse for the rest of the list
        first->next = swapPairsRecursive(second->next);
        second->next = first;

        // New head of the swapped pair is 'second'
        return second;
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

    std::cout << "Testing Swap Nodes in Pairs (Iterative):\n";

    // Test 1
    ListNode* head1 = createList({1, 2, 3, 4});
    std::cout << "Input: [1,2,3,4] -> Output: ";
    ListNode* result1 = sol.swapPairs(head1);
    printList(result1); // Expected: [2,1,4,3]
    deleteList(result1);

    // Test 2
    ListNode* head2 = createList({});
    std::cout << "Input: [] -> Output: ";
    ListNode* result2 = sol.swapPairs(head2);
    printList(result2); // Expected: []
    deleteList(result2);

    // Test 3
    ListNode* head3 = createList({1});
    std::cout << "Input: [1] -> Output: ";
    ListNode* result3 = sol.swapPairs(head3);
    printList(result3); // Expected: [1]
    deleteList(result3);

    // Test 4
    ListNode* head4 = createList({1, 2, 3});
    std::cout << "Input: [1,2,3] -> Output: ";
    ListNode* result4 = sol.swapPairs(head4);
    printList(result4); // Expected: [2,1,3]
    deleteList(result4);

    std::cout << "\nTesting Swap Nodes in Pairs (Recursive):\n";

    // Test 5
    ListNode* head5 = createList({1, 2, 3, 4});
    std::cout << "Input: [1,2,3,4] -> Output: ";
    ListNode* result5 = sol.swapPairsRecursive(head5);
    printList(result5); // Expected: [2,1,4,3]
    deleteList(result5);

    // Test 6
    ListNode* head6 = createList({});
    std::cout << "Input: [] -> Output: ";
    ListNode* result6 = sol.swapPairsRecursive(head6);
    printList(result6); // Expected: []
    deleteList(result6);

    return 0;
}
