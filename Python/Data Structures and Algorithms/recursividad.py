def multiplicacion(a:int,b:int)->int:
    if b==0: return 0
    return a + multiplicacion(a,b-1)

def interes_recapitalizable(capital,tiempo)-> float:
    if time==0: return cap
    return interes_recapitalizable(capital*1.05,tiempo-1)

def maximo_comun_divisor(a,b) ->int:
    if a==0: return b
    elif b==0: return a
    elif a>=b return maximo_comun_divisor(a-b,b)
    elif a<b return maximo_comun_divisor(a,b-a)



print("Multiplicacion de 3 y 4: "+multiplicacion(3,4))

print("Interes recapitalizable de 300 en 4 meses: "+interes_recapitalizable(3,4))

print("Maximo comun divisor de 3 y 4: "+maximo_comun_divisor(3,4))