/*
Problem 25: Reverse Nodes in k-Group
https://leetcode.com/problems/reverse-nodes-in-k-group/

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k, then the remaining nodes, in the end, should remain as they are.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Constraints:
- The number of nodes in the list is in the range [0, 5000].
- 0 <= Node.val <= 1000
- 1 <= k <= 5000
*/

#include <iostream>
#include <vector>
#include <stack>

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
    // Approach 1: Iterative (using a stack)
    ListNode* reverseKGroupStack(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev_group_tail = &dummy;
        ListNode* current = head;
        std::stack<ListNode*> st;

        while (current) {
            ListNode* group_head = current;
            int count = 0;
            // Check if there are k nodes available
            while (current && count < k) {
                st.push(current);
                current = current->next;
                count++;
            }

            if (count == k) { // If k nodes are found, reverse them
                ListNode* new_group_head = st.top();
                st.pop();
                prev_group_tail->next = new_group_head;
                prev_group_tail = new_group_head;

                while (!st.empty()) {
                    prev_group_tail->next = st.top();
                    st.pop();
                    prev_group_tail = prev_group_tail->next;
                }
                prev_group_tail->next = current; // Link to the next un-reversed part

            } else { // Less than k nodes, append them as they are
                prev_group_tail->next = group_head;
                // Clear the stack as these nodes are not reversed
                while (!st.empty()) st.pop();
                break; // No more groups to process
            }
        }

        return dummy.next;
    }

    // Approach 2: Iterative (without a stack - direct reversal)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            ListNode* tail = curr;
            int count = 0;
            // Check if there are k nodes remaining in the current group
            while (tail && count < k) {
                tail = tail->next;
                count++;
            }

            if (count == k) { // If k nodes are available
                // Reverse the current k-group
                ListNode* sub_prev = nullptr;
                ListNode* sub_curr = curr;
                for (int i = 0; i < k; ++i) {
                    ListNode* next_node = sub_curr->next;
                    sub_curr->next = sub_prev;
                    sub_prev = sub_curr;
                    sub_curr = next_node;
                }

                // Connect the reversed group
                prev->next = sub_prev; // prev points to the new head of the reversed group
                curr->next = sub_curr; // current (old head) points to the next group's head

                prev = curr; // Move prev to the tail of the current reversed group
                curr = sub_curr; // Move curr to the head of the next group
            } else { // Less than k nodes, append them as they are and stop
                prev->next = curr;
                break;
            }
        }

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

    std::cout << "Testing Reverse Nodes in k-Group (Iterative with stack):\n";

    // Test 1
    ListNode* head1_1 = createList({1, 2, 3, 4, 5});
    std::cout << "Input: [1,2,3,4,5], k = 2 -> Output: ";
    ListNode* result1_1 = sol.reverseKGroupStack(head1_1, 2);
    printList(result1_1); // Expected: [2,1,4,3,5]
    deleteList(result1_1);

    // Test 2
    ListNode* head1_2 = createList({1, 2, 3, 4, 5});
    std::cout << "Input: [1,2,3,4,5], k = 3 -> Output: ";
    ListNode* result1_2 = sol.reverseKGroupStack(head1_2, 3);
    printList(result1_2); // Expected: [3,2,1,4,5]
    deleteList(result1_2);

    // Test 3
    ListNode* head1_3 = createList({1, 2, 3, 4, 5});
    std::cout << "Input: [1,2,3,4,5], k = 1 -> Output: ";
    ListNode* result1_3 = sol.reverseKGroupStack(head1_3, 1);
    printList(result1_3); // Expected: [1,2,3,4,5]
    deleteList(result1_3);

    // Test 4
    ListNode* head1_4 = createList({1, 2, 3});
    std::cout << "Input: [1,2,3], k = 4 -> Output: ";
    ListNode* result1_4 = sol.reverseKGroupStack(head1_4, 4);
    printList(result1_4); // Expected: [1,2,3]
    deleteList(result1_4);

    std::cout << "\nTesting Reverse Nodes in k-Group (Iterative without stack):\n";

    // Test 5
    ListNode* head2_1 = createList({1, 2, 3, 4, 5});
    std::cout << "Input: [1,2,3,4,5], k = 2 -> Output: ";
    ListNode* result2_1 = sol.reverseKGroup(head2_1, 2);
    printList(result2_1); // Expected: [2,1,4,3,5]
    deleteList(result2_1);

    // Test 6
    ListNode* head2_2 = createList({1, 2, 3, 4, 5});
    std::cout << "Input: [1,2,3,4,5], k = 3 -> Output: ";
    ListNode* result2_2 = sol.reverseKGroup(head2_2, 3);
    printList(result2_2); // Expected: [3,2,1,4,5]
    deleteList(result2_2);

    // Test 7
    ListNode* head2_3 = createList({1, 2, 3});
    std::cout << "Input: [1,2,3], k = 4 -> Output: ";
    ListNode* result2_3 = sol.reverseKGroup(head2_3, 4);
    printList(result2_3); // Expected: [1,2,3]
    deleteList(result2_3);

    return 0;
}
