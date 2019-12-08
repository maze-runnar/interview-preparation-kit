#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n, s):
    UD = {'U': 1, 'D': -1}
    sea_level = 0
    valley = 0
    for step in s:
        sea_level = sea_level + UD[step]
        if not sea_level and step == 'U':
            valley += 1
    return valley

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
