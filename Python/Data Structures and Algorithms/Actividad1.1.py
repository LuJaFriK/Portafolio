from random import randint
from numpy import array

def remove(arreglo,index:int):
    new_array = array([arreglo[i] for i in range(len(arreglo)) if i != index])
    return new_array

def search(arreglo,busqueda):
    for i in range(len(arreglo)):
        if arreglo[i] == busqueda:
            return i
    return -1

arreglo = array([randint(1,100000) for i in range (100)])
print(arreglo)
arreglo = remove(arreglo,2)
print(arreglo)
print(search(arreglo,99))