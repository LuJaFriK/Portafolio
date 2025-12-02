def numero_faltante(numeros:list):
    n = len(nums)
    suma = n*(n+1)//2
    return suma - sum(numeros)