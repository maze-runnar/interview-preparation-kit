/*
Problem 21: Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

Constraints:
- The number of nodes in both lists is in the range [0, 50].
- -100 <= Node.val <= 100
- Both list1 and list2 are sorted in non-decreasing order.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) {
            tail->next = list1;
        } else if (list2) {
            tail->next = list2;
        }

        return dummy.next;
    }

    // Approach 2: Recursive
    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoListsRecursive(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoListsRecursive(list1, list2->next);
            return list2;
        }
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

    std::cout << "Testing Merge Two Sorted Lists (Iterative):\n";

    // Test 1
    ListNode* l1_1 = createList({1, 2, 4});
    ListNode* l2_1 = createList({1, 3, 4});
    std::cout << "Input: list1 = "; printList(l1_1); std::cout << ", list2 = "; printList(l2_1); std::cout << " -> Output: ";
    ListNode* result1 = sol.mergeTwoLists(l1_1, l2_1);
    printList(result1);
    std::cout << " (Expected: [1,1,2,3,4,4])\n";
    deleteList(result1);

    // Test 2
    ListNode* l1_2 = createList({});
    ListNode* l2_2 = createList({});
    std::cout << "Input: list1 = "; printList(l1_2); std::cout << ", list2 = "; printList(l2_2); std::cout << " -> Output: ";
    ListNode* result2 = sol.mergeTwoLists(l1_2, l2_2);
    printList(result2);
    std::cout << " (Expected: [])\n";
    deleteList(result2);

    // Test 3
    ListNode* l1_3 = createList({});
    ListNode* l2_3 = createList({0});
    std::cout << "Input: list1 = "; printList(l1_3); std::cout << ", list2 = "; printList(l2_3); std::cout << " -> Output: ";
    ListNode* result3 = sol.mergeTwoLists(l1_3, l2_3);
    printList(result3);
    std::cout << " (Expected: [0])\n";
    deleteList(result3);

    std::cout << "\nTesting Merge Two Sorted Lists (Recursive):\n";

    // Test 4
    ListNode* l1_4 = createList({1, 2, 4});
    ListNode* l2_4 = createList({1, 3, 4});
    std::cout << "Input: list1 = "; printList(l1_4); std::cout << ", list2 = "; printList(l2_4); std::cout << " -> Output: ";
    ListNode* result4 = sol.mergeTwoListsRecursive(l1_4, l2_4);
    printList(result4);
    std::cout << " (Expected: [1,1,2,3,4,4])\n";
    deleteList(result4);

    // Test 5
    ListNode* l1_5 = createList({});
    ListNode* l2_5 = createList({});
    std::cout << "Input: list1 = "; printList(l1_5); std::cout << ", list2 = "; printList(l2_5); std::cout << " -> Output: ";
    ListNode* result5 = sol.mergeTwoListsRecursive(l1_5, l2_5);
    printList(result5);
    std::cout << " (Expected: [])\n";
    deleteList(result5);

    return 0;
}
