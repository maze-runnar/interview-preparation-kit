#!/bin/python3

import os

# Complete the isValid function below.
def isValid(s): 
    scount=[0 for i in range(26)]
    ret='YES'#return value
    for i in s: scount[ord(i)-97]+=1
    aux=[i for i in scount if i!=0]
    d={}
    max_value=0
    for i in aux:
        d[i]=d.get(i,0)+1
        if d[i]>max_value:
            max_key,max_value=i,d[i]#most frequent
    diff_elem_count=0
    for i in d:
        if i!=max_key:
            if i==max_key+1 or i==1:
                diff_elem_count+=d[i]
                if diff_elem_count>1:
                    ret='NO'
                    break
            else:
                ret='NO'
                break
    return ret

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
