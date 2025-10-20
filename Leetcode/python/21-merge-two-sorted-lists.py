# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    # Approach 1: Iterative
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

    # Approach 2: Recursive
    def mergeTwoListsRecursive(self, list1: ListNode, list2: ListNode) -> ListNode:
        if not list1: return list2
        if not list2: return list1

        if list1.val <= list2.val:
            list1.next = self.mergeTwoListsRecursive(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoListsRecursive(list1, list2.next)
            return list2

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

    print("Testing Merge Two Sorted Lists (Iterative):")

    # Test 1
    arr1_1 = [1, 2, 4]
    arr2_1 = [1, 3, 4]
    head1_1 = createList(arr1_1)
    head2_1 = createList(arr2_1)
    print(f"Input: list1 = {arr1_1}, list2 = {arr2_1} -> Output: ", end="")
    result1 = sol.mergeTwoLists(head1_1, head2_1)
    printList(result1) # Expected: [1, 1, 2, 3, 4, 4]

    # Test 2
    arr1_2 = []
    arr2_2 = []
    head1_2 = createList(arr1_2)
    head2_2 = createList(arr2_2)
    print(f"Input: list1 = {arr1_2}, list2 = {arr2_2} -> Output: ", end="")
    result2 = sol.mergeTwoLists(head1_2, head2_2)
    printList(result2) # Expected: []

    # Test 3
    arr1_3 = []
    arr2_3 = [0]
    head1_3 = createList(arr1_3)
    head2_3 = createList(arr2_3)
    print(f"Input: list1 = {arr1_3}, list2 = {arr2_3} -> Output: ", end="")
    result3 = sol.mergeTwoLists(head1_3, head2_3)
    printList(result3) # Expected: [0]

    print("\nTesting Merge Two Sorted Lists (Recursive):")

    # Test 4
    arr1_4 = [1, 2, 4]
    arr2_4 = [1, 3, 4]
    head1_4 = createList(arr1_4)
    head2_4 = createList(arr2_4)
    print(f"Input: list1 = {arr1_4}, list2 = {arr2_4} -> Output: ", end="")
    result4 = sol.mergeTwoListsRecursive(head1_4, head2_4)
    printList(result4) # Expected: [1, 1, 2, 3, 4, 4]

    # Test 5
    arr1_5 = []
    arr2_5 = []
    head1_5 = createList(arr1_5)
    head2_5 = createList(arr2_5)
    print(f"Input: list1 = {arr1_5}, list2 = {arr2_5} -> Output: ", end="")
    result5 = sol.mergeTwoListsRecursive(head1_5, head2_5)
    printList(result5) # Expected: []
