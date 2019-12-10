/*
Detect a cycle in a linked list. Note that the head pointer may be 'null' if the list is empty.

A Node is defined as: 
    class Node {
        int data;
        Node next;
    }
*/

boolean hasCycle(Node head) {
    if(head==null || head.next==null)
            return false;
    Node slow = head, fast = head;
    while(fast!=null && fast.next!=null )
    {
        slow = slow.next;
        fast = fast.next.next;
        if(slow==fast)
            return true;
    }
    return false;
        
}