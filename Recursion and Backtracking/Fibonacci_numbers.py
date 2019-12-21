cache = {0:0, 1:1}

def fibonacci(n):
    try:
        return cache[n]
    except KeyError:
        cache[n] = fibonacci(n - 1) + fibonacci(n - 2)
        return cache[n]

n = int(input())
print(fibonacci(n))
