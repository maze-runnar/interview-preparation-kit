# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    # Approach 1: Two Pass Algorithm
    def removeNthFromEndTwoPass(self, head: ListNode, n: int) -> ListNode:
        if not head: 
            return None

        length = 0
        current = head
        while current:
            length += 1
            current = current.next

        if length == n: # Remove the head
            new_head = head.next
            del head
            return new_head

        current = head
        for _ in range(length - n - 1):
            current = current.next
        
        node_to_delete = current.next
        current.next = current.next.next
        del node_to_delete

        return head

    # Approach 2: One Pass Algorithm using Two Pointers
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if not head: 
            return None

        dummy = ListNode(0)
        dummy.next = head
        first = dummy
        second = dummy

        # Move first pointer n+1 steps ahead
        for _ in range(n + 1):
            first = first.next

        # Move both pointers until first reaches the end
        while first:
            first = first.next
            second = second.next

        # second is now at the node just before the one to be removed
        node_to_delete = second.next
        second.next = second.next.next
        del node_to_delete

        return dummy.next

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

    print("Testing Remove Nth Node From End of List:")

    # Test 1
    arr1 = [1, 2, 3, 4, 5]
    head1 = createList(arr1)
    print(f"Input: {arr1}, n = 2 -> Output: ", end="")
    result1 = sol.removeNthFromEnd(head1, 2)
    printList(result1) # Expected: [1, 2, 3, 5]

    # Test 2
    arr2 = [1]
    head2 = createList(arr2)
    print(f"Input: {arr2}, n = 1 -> Output: ", end="")
    result2 = sol.removeNthFromEnd(head2, 1)
    printList(result2) # Expected: []

    # Test 3
    arr3 = [1, 2]
    head3 = createList(arr3)
    print(f"Input: {arr3}, n = 1 -> Output: ", end="")
    result3 = sol.removeNthFromEnd(head3, 1)
    printList(result3) # Expected: [1]

    # Test 4
    arr4 = [1, 2, 3]
    head4 = createList(arr4)
    print(f"Input: {arr4}, n = 3 -> Output: ", end="")
    result4 = sol.removeNthFromEnd(head4, 3)
    printList(result4) # Expected: [2, 3]
