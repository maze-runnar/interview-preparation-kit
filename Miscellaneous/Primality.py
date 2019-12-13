#!/bin/python3

import math
import os
import random
import re
import sys
from math import sqrt 

def primality(p):
    if p < 2:
        return 'Not prime'
    elif p <= 3:
        return 'Prime'
    elif p % 2 == 0 or p % 3 == 0:
        return 'Not prime'
    else:
        for i in range(3, int(sqrt(p)+1), 2):
            if p % i == 0:
                return 'Not prime'
    return 'Prime'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    p = int(input())

    for p_itr in range(p):
        n = int(input())

        result = primality(n)

        fptr.write(result + '\n')

    fptr.close()
