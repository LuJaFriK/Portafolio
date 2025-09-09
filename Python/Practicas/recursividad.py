def pot(numero:int,n:int)->int:
    if n == 1:  return numero
    else: return numero * pot(numero,n-1)

print(pot(3,3))
