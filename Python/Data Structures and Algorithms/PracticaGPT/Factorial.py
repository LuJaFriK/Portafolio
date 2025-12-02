def factorial(numero:int):
    if numero == 1: return numero
    return numero * factorial(numero-1)


print(factorial(7))