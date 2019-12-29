#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the birthdayCakeCandles function below.
def birthdayCakeCandles(ar):
    hash_table = dict()
    max_val = 0
    for i in ar:
        if i in hash_table.keys():
            hash_table[i]+=1
        else:
            hash_table[i] = 1
        if i>max_val:
            max_val = i
    return hash_table[max_val]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ar_count = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = birthdayCakeCandles(ar)

    fptr.write(str(result) + '\n')

    fptr.close()
