# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    # Approach 1: Iterative
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        while prev.next and prev.next.next:
            first = prev.next
            second = prev.next.next

            # Swapping
            first.next = second.next
            second.next = first
            prev.next = second

            # Move to the next pair
            prev = first
        
        return dummy.next

    # Approach 2: Recursive
    def swapPairsRecursive(self, head: ListNode) -> ListNode:
        # Base case: no node or only one node, nothing to swap
        if not head or not head.next:
            return head

        # Nodes to be swapped
        first = head
        second = head.next

        # Recurse for the rest of the list
        first.next = self.swapPairsRecursive(second.next)
        second.next = first

        # New head of the swapped pair is 'second'
        return second

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

    print("Testing Swap Nodes in Pairs (Iterative):")

    # Test 1
    head1 = createList([1, 2, 3, 4])
    print(f"Input: [1,2,3,4] -> Output: ", end="")
    result1 = sol.swapPairs(head1)
    printList(result1) # Expected: [2,1,4,3]

    # Test 2
    head2 = createList([])
    print(f"Input: [] -> Output: ", end="")
    result2 = sol.swapPairs(head2)
    printList(result2) # Expected: []

    # Test 3
    head3 = createList([1])
    print(f"Input: [1] -> Output: ", end="")
    result3 = sol.swapPairs(head3)
    printList(result3) # Expected: [1]

    # Test 4
    head4 = createList([1, 2, 3])
    print(f"Input: [1,2,3] -> Output: ", end="")
    result4 = sol.swapPairs(head4)
    printList(result4) # Expected: [2,1,3]

    print("\nTesting Swap Nodes in Pairs (Recursive):\n")

    # Test 5
    head5 = createList([1, 2, 3, 4])
    print(f"Input: [1,2,3,4] -> Output: ", end="")
    result5 = sol.swapPairsRecursive(head5)
    printList(result5) # Expected: [2,1,4,3]

    # Test 6
    head6 = createList([])
    print(f"Input: [] -> Output: ", end="")
    result6 = sol.swapPairsRecursive(head6)
    printList(result6) # Expected: []
