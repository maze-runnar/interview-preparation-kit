#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

# Complete the reverseShuffleMerge function below.
def reverseShuffleMerge(s):
    word = []
    freqs = Counter(s)
    reqs = { k: v/2 for k, v in freqs.items()}  # required letters
    avail_skips = { k: v/2 for k, v in freqs.items()}  # available skips
    skipped = []  # short history of letters that have been skipped
    
    for c in reversed(s):
        # No longer need this character so skip
        if reqs[c] == 0:
            continue
        
        # Skip current character if possible
        if avail_skips[c] > 0:
            avail_skips[c] -= 1
            skipped.append(c)  # track history of skipped chars to add back in to the word later

        ### Can no longer skip current character
        ## If history of skipped chars is empty then just add the current character
        elif len(skipped) == 0:
            word.append(c)
            
        ## Else add back all skipped characters from cheapest to current letter
        else:
            i = 0
            skipped.append(c)
            avail_skips[c] -= 1
            min_c = chr(ord('a') - 1)

            while i < len(skipped):
                # find the cheapest skipped character
                i = index_of(skipped, find_min_bounded(skipped, i, min_c), i)
                sc = skipped[i]
                
                # if this skipped character (sc) is already fulfilled go to next cheapest
                if reqs[sc] == 0:
                    min_c = sc
                    continue

                # process the current sc
                word.append(sc)
                reqs[sc] -= 1
                avail_skips[sc] += 1
                i += 1

                # if the sc is at the current character 
                # we've processed one instance of it making it skippable again ... so break
                if sc == c:
                    break                

            # clear out all skipped characters that we've already processed
            skipped = skipped[i:]

    return ''.join(word)


def find_min_bounded(arr, start, min_c):
    m = 'z'
    for i in range(start, len(arr)):
        if arr[i] < m and arr[i] > min_c:
            m = arr[i]
    return m


def index_of(arr, v, start):
    for i in range(start, len(arr)):
        if arr[i] == v:
            return i


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = reverseShuffleMerge(s)

    fptr.write(result + '\n')

    fptr.close()