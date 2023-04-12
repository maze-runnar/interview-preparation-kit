#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the twoStrings function below.
def twoStrings(s1, s2):
    # Convert both strings to sets to obtain unique characters
    set_s1 = set(s1)
    set_s2 = set(s2)

    # Compute the intersection of the two sets
    intersection = set_s1 & set_s2

    # Return 'YES' if the intersection is not empty, otherwise 'NO'
    return 'YES' if intersection else 'NO'
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s1 = input()

        s2 = input()

        result = twoStrings(s1, s2)

        fptr.write(result + '\n')

    fptr.close()
