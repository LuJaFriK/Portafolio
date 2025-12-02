def Fibonacci(n:int):
    ant = 0
    pos = 1
    for i in range(2,n+1):
        n = ant+pos
        ant = pos
        pos = n
    return pos

print(Fibonacci(10))