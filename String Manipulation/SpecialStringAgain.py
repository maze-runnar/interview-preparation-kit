#!/bin/python3

import os
import itertools as it

# Complete the substrCount function below.
def substrCount(n, s):
    if n == 1:
        return 1      
    s = [list(g) for k, g in it.groupby(s)]
    res = sum([int(len(i)*(len(i)+1)/2) for i in s])

    for i in range(len(s)):
        if i == 0 or i == len(s)-1 or len(s[i]) > 1 :
            continue
        if s[i-1][0] == s[i+1][0]:
            res+= min(len(s[i-1]), len(s[i+1]))
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = substrCount(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
