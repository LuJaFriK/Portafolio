def multiplicacion(a:int,b:int)->int:
    if b==0: return 0
    return a + multiplicacion(a,b-1)

print(multiplicacion(3,4))    