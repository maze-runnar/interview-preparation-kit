#!/bin/python3

import os

# Complete the makeAnagram function below.
def makeAnagram(a, b):
    for i in a:
        if i in b:
            b=b.replace(i,'',1)
            a=a.replace(i,'',1)
    return len(a)+len(b)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = input()

    b = input()

    res = makeAnagram(a, b)

    fptr.write(str(res) + '\n')

    fptr.close()
