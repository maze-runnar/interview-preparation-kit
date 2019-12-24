#!/bin/python3

import math
import os
import random
import re
import sys
def flavors(m,a):
    prices = {}
    for idx, p in enumerate(a):
        if m-p in prices:
            return prices[m-p], idx
        prices[p] = idx
    return None

t = int(input().strip())
for a0 in range(t):
    m = int(input().strip())
    n = int(input().strip())
    a = list(map(int, input().strip().split(' ')))
    f1, f2 = flavors(m,a)
    print(f1+1, f2+1)

