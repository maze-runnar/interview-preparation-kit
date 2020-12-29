def merge(a,b,arr):
    i=0
    j=0
    k=0
    while i<len(a) and j<len(b):
        if a[i]<b[j]:
            a[k]=a[i]
            i=i+1
            k=k+1
        else:
            a[k]=b[j]
            j=j+1
            k=k+1
    while i<len(a):
       a[k]=a[i]
       i=i+1
       k=k+1
   while j<len(b):
        a[k]=b[j]
        k=k+1
        j=j+1
       
def mergesort(arr):
    if len(arr)==1 or len(arr)==0:
        return
    mid=len(arr)//2
    a=[0:mid]
    b=[mid:]
    merge(a,b,arr)
