#!/bin/python3

#import math
import os
#import random
#import re
#import sys

class DoublyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = DoublyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node
            node.prev = self.tail

        self.tail = node

def print_doubly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))

        node = node.next

        if node:
            fptr.write(sep)

# Complete the sortedInsert function below.

#
# For your reference:
#
# DoublyLinkedListNode:
#     int data
#     DoublyLinkedListNode next
#     DoublyLinkedListNode prev
#
#

class Node(object): 
    def __init__(self, data=None, next_node=None, prev_node = None):
        self.data = data
        self.next = next_node
        self.prev = prev_node

def sortedInsert(head, data):
    if head == None:
        return Node(data)

    walker = head
    while walker.next != None and walker.data < data:
        walker = walker.next
        if walker.data < data:
        walker.next = Node(data, None, walker)
    elif walker.prev == None:
        node = Node(data, head)
        head.prev = node
        head = node
    else:
        node = Node(data, walker, walker.prev)
        walker.prev.next = node
        walker.prev = node

    return head

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        llist_count = int(input())

        llist = DoublyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        data = int(input())

        llist1 = sortedInsert(llist.head, data)

        print_doubly_linked_list(llist1, ' ', fptr)
        fptr.write('\n')

    fptr.close()
