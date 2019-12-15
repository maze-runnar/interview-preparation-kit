#!/bin/python3

import math
import os
import random
import re
import sys

def findItems(machines,temp):
    ans = 0
    for i in range(len(machines)):
        ans += temp // machines[i]
    return ans

def BinarySearch(machines,goal,high):
    low = 1
    while low < high:
        mid = (low + high) >> 1
        item = findItems(machines,mid)
        if item < goal:
            low = mid + 1
        else:
            high = mid
    return high
# Complete the minTime function below.
def minTime(machines, goal):
    maxval = -sys.maxsize 
    for i in range(len(machines)): 
        maxval = max(maxval, machines[i]) 
    return BinarySearch(machines,goal,maxval * goal)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nGoal = input().split()

    n = int(nGoal[0])

    goal = int(nGoal[1])

    machines = list(map(int, input().rstrip().split()))

    ans = minTime(machines, goal)

    fptr.write(str(ans) + '\n')

    fptr.close()
