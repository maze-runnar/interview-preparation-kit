#!/bin/python3

import math
import os
import random
import re
import sys
import collections

# Complete the riddle function below.
def riddle(arr):
    stack = collections.deque()
    max_window = {}
    arr += [0,]
    for i, n in enumerate(arr):
        if not stack or n > stack[-1][1]:
            stack.append((i, n))
        else:
            while stack and stack[-1][1] >= n:
                if i-stack[-1][0] not in max_window or max_window[i-stack[-1][0]] < stack[-1][1]:
                    max_window[i-stack[-1][0]] = stack[-1][1]
                p = stack.pop()
            stack.append((p[0], n))
    ans = [0]*(len(arr)-1)
    v_ant = min(max_window.values())
    for i in range(len(arr)-1, 0, -1):
        if i in max_window and max_window[i] > v_ant:
            ans[i-1] = max_window[i]
            v_ant = max_window[i]
        else:
           ans[i-1] = v_ant
    return ans
    # complete this function

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = riddle(arr)

    fptr.write(' '.join(map(str, res)))
    fptr.write('\n')

    fptr.close()
