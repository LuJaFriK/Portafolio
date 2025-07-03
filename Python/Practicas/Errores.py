#Errores más comunes en python:

#Error de sintaxis, como olvidar unos dos puntos o escribir mal una palabra reservada
def Sintax_error(): #El nombre de una funcion no puede llevar espacios
    return "Error"

#Error de nombre, como hacer llamar a una funcion o variable que no existe
print(pepe)

#Error de tipo, como querer operar entre dos tipos distintos de datos

x = lambda x : x+"10" #Esto funciona porque es una funcion que retorna un string, pero no funciona en variables enteras

#Error de indice, cuando se intenta acceder a un indice de un arreglo que no existe

tupla = (1,2,3) ; print(tupla[3])

#Para manejar los errores se usa un try: {codigo} except "Error": {bloque que se ejecuta en caso de error}

try:
    1+input("Pon cualquer cosa we")
except ValueError: #Es como el catch de java
    print("Esta mal hecho el codigo we")
#Tambien tenemos el finally
finally:
    print("Yazed es mi bro")
