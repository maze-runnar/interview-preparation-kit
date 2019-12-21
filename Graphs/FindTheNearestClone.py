#!/bin/python3

import math
import os
import random
import re
import sys
import collections
# Complete the findShortest function below.

#
# For the weighted graph, <name>:
#
# 1. The number of nodes is <name>_nodes.
# 2. The number of edges is <name>_edges.
# 3. An edge exists between <name>_from[i] to <name>_to[i].
#
#
class Node:
    def __init__(self, index):
        self.index = index
        self.neighbors = set()

    def conn(self, other):
        self.neighbors.add(other)
        other.neighbors.add(self)


def findShortest(graph_nodes, graph_from, graph_to, ids, val):
    nodes = { i + 1: Node(i + 1) for i in range(graph_nodes) }
    for start, end in zip(graph_from, graph_to):
        nodes[start].conn(nodes[end])

    queue = collections.deque()
    visited = {}

    for i, id in enumerate(ids):
        if id == val:
            visited[i + 1] = (i + 1, 0)
            queue.append(nodes[i + 1])
    
    while queue:
        current = queue.popleft()
        source, path_len = visited[current.index]

        for n in current.neighbors:
            if n.index not in visited:
                visited[n.index] = (source, path_len + 1)
                queue.append(n)
            else:
                if visited[n.index][0] == source:
                    continue
                return path_len + visited[n.index][1] + 1

    return -1


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    graph_nodes, graph_edges = map(int, input().split())

    graph_from = [0] * graph_edges
    graph_to = [0] * graph_edges

    for i in range(graph_edges):
        graph_from[i], graph_to[i] = map(int, input().split())

    ids = list(map(int, input().rstrip().split()))

    val = int(input())

    ans = findShortest(graph_nodes, graph_from, graph_to, ids, val)

    fptr.write(str(ans) + '\n')

    fptr.close()
