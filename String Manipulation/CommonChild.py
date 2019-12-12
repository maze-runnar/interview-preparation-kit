#!/bin/python3

import os

# Complete the commonChild function below.
def commonChild(s1, s2):
    l1 = len(s1)
    l2 = len(s2)

    lcs = [[0]*(len(s1)+1) for _ in range(2)]

    for i in range(l1):
        li1 = (i+1)%2
        li = i%2

        for j in range(l2): 
            if s1[i] == s2[j]:
                lcs[li1][j+1] = (lcs[li][j] + 1) 
            elif lcs[li1][j] > lcs[li][j+1]:
                lcs[li1][j+1] = lcs[li1][j] 
            else:
                lcs[li1][j+1] = lcs[li][j+1]

    return lcs[(i+1)%2][j+1]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s1 = input()

    s2 = input()

    result = commonChild(s1, s2)

    fptr.write(str(result) + '\n')

    fptr.close()
