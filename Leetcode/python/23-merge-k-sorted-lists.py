# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    # Helper function to merge two sorted lists (from Problem 21)
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        if not list1: return list2
        if not list2: return list1

        dummy = ListNode(0)
        tail = dummy

        while list1 and list2:
            if list1.val <= list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        
        if list1:
            tail.next = list1
        elif list2:
            tail.next = list2
        
        return dummy.next

    # Approach: Divide and Conquer
    def mergeKLists(self, lists: list[ListNode]) -> ListNode:
        if not lists:
            return None
        if len(lists) == 1:
            return lists[0]

        return self._mergeKListsHelper(lists, 0, len(lists) - 1)

    def _mergeKListsHelper(self, lists: list[ListNode], start: int, end: int) -> ListNode:
        if start == end:
            return lists[start]
        
        mid = start + (end - start) // 2
        left_merged = self._mergeKListsHelper(lists, start, mid)
        right_merged = self._mergeKListsHelper(lists, mid + 1, end)
        
        return self.mergeTwoLists(left_merged, right_merged)

# Helper function to print the list
def printList(head: ListNode):
    current = head
    result = []
    while current:
        result.append(current.val)
        current = current.next
    print(result)

# Helper function to create a list from a Python list
def createList(arr: list) -> ListNode:
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for i in range(1, len(arr)):
        current.next = ListNode(arr[i])
        current = current.next
    return head

# Test cases
if __name__ == "__main__":
    sol = Solution()

    print("Testing Merge k Sorted Lists:")

    # Test 1
    lists1_input = [[1, 4, 5], [1, 3, 4], [2, 6]]
    lists1_nodes = [createList(arr) for arr in lists1_input]
    print(f"Input: lists = {lists1_input} -> Output: ", end="")
    result1 = sol.mergeKLists(lists1_nodes)
    printList(result1) # Expected: [1, 1, 2, 3, 4, 4, 5, 6]

    # Test 2
    lists2_input = []
    lists2_nodes = [createList(arr) for arr in lists2_input]
    print(f"Input: lists = {lists2_input} -> Output: ", end="")
    result2 = sol.mergeKLists(lists2_nodes)
    printList(result2) # Expected: []

    # Test 3
    lists3_input = [[]]
    lists3_nodes = [createList(arr) for arr in lists3_input]
    print(f"Input: lists = {lists3_input} -> Output: ", end="")
    result3 = sol.mergeKLists(lists3_nodes)
    printList(result3) # Expected: []

    # Test 4 (more complex)
    lists4_input = [[-1, 5, 11], [6, 10], [1, 2, 3]]
    lists4_nodes = [createList(arr) for arr in lists4_input]
    print(f"Input: lists = {lists4_input} -> Output: ", end="")
    result4 = sol.mergeKLists(lists4_nodes)
    printList(result4) # Expected: [-1, 1, 2, 3, 5, 6, 10, 11]
