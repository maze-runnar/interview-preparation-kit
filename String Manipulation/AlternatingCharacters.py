#!/bin/python3

import os

# Complete the alternatingCharacters function below.
def alternatingCharacters(s):
    count = 0
    for num in range (len(s)-1):
        if s[num] == s[num+1]:
            count +=1
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = alternatingCharacters(s)

        fptr.write(str(result) + '\n')

    fptr.close()
