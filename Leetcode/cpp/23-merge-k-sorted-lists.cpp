/*
Problem 23: Merge k Sorted Lists
https://leetcode.com/problems/merge-k-sorted-lists/

You are given an array of k linked-lists lists, each sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
- k == lists.length
- 0 <= k <= 10^4
- 0 <= lists[i].length <= 500
- -10^4 <= lists[i][j] <= 10^4
- lists[i] is sorted in ascending order.
- The sum of lists[i].length will not exceed 10^4.
*/

#include <vector>
#include <queue>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Custom comparator for the priority queue
struct CompareListNode {
    bool operator()(ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    // Approach 1: Merge One by One
    ListNode* mergeKListsOneByOne(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        ListNode* mergedList = nullptr;
        for (ListNode* list : lists) {
            mergedList = mergeTwoLists(mergedList, list);
        }
        return mergedList;
    }

    // Helper function to merge two sorted lists (from Problem 21)
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

    // Approach 2: Using a Min-Priority Queue (Heap)
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, CompareListNode> pq;

        // Add the head of each list to the priority queue
        for (ListNode* list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }

    // Approach 3: Divide and Conquer
    ListNode* mergeKListsDivideConquer(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeKListsHelper(std::vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start > end) {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        return mergeTwoLists(left, right);
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

    std::cout << "Testing Merge K Sorted Lists (Min-Priority Queue):\n";

    // Test 1
    std::vector<ListNode*> lists1 = {createList({1, 4, 5}), createList({1, 3, 4}), createList({2, 6})};
    std::cout << "Input: lists = [[1,4,5],[1,3,4],[2,6]] -> Output: ";
    ListNode* result1 = sol.mergeKLists(lists1);
    printList(result1); // Expected: [1,1,2,3,4,4,5,6]
    deleteList(result1);
    for(ListNode* node : lists1) deleteList(node); // Clean up original lists

    // Test 2
    std::vector<ListNode*> lists2 = {};
    std::cout << "Input: lists = [] -> Output: ";
    ListNode* result2 = sol.mergeKLists(lists2);
    printList(result2); // Expected: []
    deleteList(result2);

    // Test 3
    std::vector<ListNode*> lists3 = {createList({})};
    std::cout << "Input: lists = [[]] -> Output: ";
    ListNode* result3 = sol.mergeKLists(lists3);
    printList(result3); // Expected: []
    deleteList(result3);
    for(ListNode* node : lists3) deleteList(node); // Clean up original lists

    std::cout << "\nTesting Merge K Sorted Lists (Divide and Conquer):\n";

    // Test 4
    std::vector<ListNode*> lists4 = {createList({1, 4, 5}), createList({1, 3, 4}), createList({2, 6})};
    std::cout << "Input: lists = [[1,4,5],[1,3,4],[2,6]] -> Output: ";
    ListNode* result4 = sol.mergeKListsDivideConquer(lists4);
    printList(result4); // Expected: [1,1,2,3,4,4,5,6]
    deleteList(result4);
    for(ListNode* node : lists4) deleteList(node); // Clean up original lists

    // Test 5
    std::vector<ListNode*> lists5 = {};
    std::cout << "Input: lists = [] -> Output: ";
    ListNode* result5 = sol.mergeKListsDivideConquer(lists5);
    printList(result5); // Expected: []
    deleteList(result5);

    return 0;
}
