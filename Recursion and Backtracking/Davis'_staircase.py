import os

a = ((19+3*33**(1/2))**(1/3) + (19-3*33**(1/2))**(1/3) + 1)/3
c = (a - 1)/(4*a - 6)

trib = lambda n: int(round(c * (a ** n)))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    s = int(input())
    for s_itr in range(s):
        n = int(input())
        res = trib(n)
        fptr.write(str(res) + '\n')
    fptr.close()
