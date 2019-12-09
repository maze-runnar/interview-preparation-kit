#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countSwaps function below.
def countSwaps(a):
    numSwaps = 0

    while True:
        SwapsFlag = False
        for i in range(len(a)-1):
            if a[i] > a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
                numSwaps += 1
                SwapsFlag = True
        if not SwapsFlag:
            break
    print('Array is sorted in', numSwaps, 'swaps.')
    print('First Element:', a[0])
    print('Last Element:', a[-1])

if __name__ == '__main__':
    n = int(input())

    a = list(map(int, input().rstrip().split()))

    countSwaps(a)
