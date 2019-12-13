#!/bin/python3

import math
import os
import random
import re
import sys

def init_cmp(mp,x,y):
    if x not in mp:
        mp[x]=x
    if y not in mp:
        mp[y]=y

def init_cc(cc,x,y):
    if x not in cc:
        cc[x]=1
    if y not in cc:
        cc[y]=1

def get_parent(mp,x):
    while mp[x]!=x:
        x=mp[x]
    return x

# Complete the maxCircle function below.
def maxCircle(queries):
    mp = {}
    cc = {}
    max_gp = 0
    res = []
    for q in queries:
        init_cmp(mp,q[0],q[1])
        init_cc(cc,q[0],q[1])
        p1 = get_parent(mp,q[0])
        p2 = get_parent(mp,q[1])
        if p1!=p2:
            if cc[p1]>cc[p2]:
                mp[p2]=p1
                cc[p1]=cc[p1]+cc[p2]
            else:
                mp[p1]=p2
                cc[p2]=cc[p1]+cc[p2]
            max_gp = max(max_gp,max(cc[p1],cc[p2]))
        res.append(max_gp)
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))

    ans = maxCircle(queries)

    fptr.write('\n'.join(map(str, ans)))
    fptr.write('\n')

    fptr.close()
