# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    # Approach 1: Iterative (without a stack - direct reversal)
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or k == 1:
            return head

        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        curr = head

        while curr:
            tail = curr
            count = 0
            # Check if there are k nodes remaining in the current group
            while tail and count < k:
                tail = tail.next
                count += 1

            if count == k:  # If k nodes are available
                # Reverse the current k-group
                sub_prev = None
                sub_curr = curr
                for _ in range(k):
                    next_node = sub_curr.next
                    sub_curr.next = sub_prev
                    sub_prev = sub_curr
                    sub_curr = next_node

                # Connect the reversed group
                prev.next = sub_prev  # prev points to the new head of the reversed group
                curr.next = sub_curr  # current (old head) points to the next group's head

                prev = curr  # Move prev to the tail of the current reversed group
                curr = sub_curr  # Move curr to the head of the next group
            else:  # Less than k nodes, append them as they are and stop
                prev.next = curr
                break

        return dummy.next

    # Approach 2: Recursive
    def reverseKGroupRecursive(self, head: ListNode, k: int) -> ListNode:
        current = head
        count = 0
        # Check if there are at least k nodes remaining
        while current and count < k:
            current = current.next
            count += 1
        
        # If we have k nodes, then reverse them
        if count == k:
            current = self.reverseKGroupRecursive(current, k)  # Recursively reverse the next k-group
            
            # Reverse the current k nodes
            for _ in range(k):
                temp = head.next
                head.next = current
                current = head
                head = temp
            head = current
        
        return head

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

    print("Testing Reverse Nodes in k-Group (Iterative):\n")

    # Test 1
    head1_1 = createList([1, 2, 3, 4, 5])
    print(f"Input: [1,2,3,4,5], k = 2 -> Output: ", end="")
    result1_1 = sol.reverseKGroup(head1_1, 2)
    printList(result1_1) # Expected: [2,1,4,3,5]

    # Test 2
    head1_2 = createList([1, 2, 3, 4, 5])
    print(f"Input: [1,2,3,4,5], k = 3 -> Output: ", end="")
    result1_2 = sol.reverseKGroup(head1_2, 3)
    printList(result1_2) # Expected: [3,2,1,4,5]

    # Test 3
    head1_3 = createList([1, 2, 3, 4, 5])
    print(f"Input: [1,2,3,4,5], k = 1 -> Output: ", end="")
    result1_3 = sol.reverseKGroup(head1_3, 1)
    printList(result1_3) # Expected: [1,2,3,4,5]

    # Test 4
    head1_4 = createList([1, 2, 3])
    print(f"Input: [1,2,3], k = 4 -> Output: ", end="")
    result1_4 = sol.reverseKGroup(head1_4, 4)
    printList(result1_4) # Expected: [1,2,3]

    print("\nTesting Reverse Nodes in k-Group (Recursive):\n")

    # Test 5
    head2_1 = createList([1, 2, 3, 4, 5])
    print(f"Input: [1,2,3,4,5], k = 2 -> Output: ", end="")
    result2_1 = sol.reverseKGroupRecursive(head2_1, 2)
    printList(result2_1) # Expected: [2,1,4,3,5]

    # Test 6
    head2_2 = createList([1, 2, 3, 4, 5])
    print(f"Input: [1,2,3,4,5], k = 3 -> Output: ", end="")
    result2_2 = sol.reverseKGroupRecursive(head2_2, 3)
    printList(result2_2) # Expected: [3,2,1,4,5]

    # Test 7
    head2_3 = createList([1, 2, 3])
    print(f"Input: [1,2,3], k = 4 -> Output: ", end="")
    result2_3 = sol.reverseKGroupRecursive(head2_3, 4)
    printList(result2_3) # Expected: [1,2,3]
