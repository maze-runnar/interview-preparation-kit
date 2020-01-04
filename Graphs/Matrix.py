#!/bin/python3

def root(v):
    if par[v] == v:
        return v
    par[v] = root(par[v])
    return par[v]


def merge(x, y):
    if root(x) in c:
        par[y] = root(x)
    else:
        par[x] = root(y)

if __name__ == "__main__":
    n, k = map(int, input().split())
    g = [list(map(int, input().split())) for _ in range(n-1)]
    c = {int(input()) for _ in range(k)}
    r = 0
    par = [u for u in range(n)]
    for u, v, w in sorted(g, key=lambda x: -x[2]):
        if root(u) in c and root(v) in c:
            r += w
            continue
        merge(root(u), root(v))
    print(r)
