#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the birthdayCakeCandles function below.
def birthdayCakeCandles(ar):
    if len(ar) == 0:
        return 0
    ar.sort()
    max_ar = ar[-1]
    count = 1
    ar.reverse()
    print(ar)
    for i in range(1,len(ar)):
        print(ar[i])
        if ar[i] == max_ar:
            count += 1
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ar_count = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = birthdayCakeCandles(ar)

    fptr.write(str(result) + '\n')

    fptr.close()
