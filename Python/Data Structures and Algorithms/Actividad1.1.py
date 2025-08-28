from numpy import array ; from random import randint

def search(arreglo,busqueda):
    index = -1
    for i in range(len(arreglo)):
        if arreglo[i] == busqueda:
            index = i
    if index == -1: print("El numero no fue encontrado.")
    return index

def remove(arreglo,busqueda:int):
    index = search(arreglo,busqueda)
    if index > -1:
        for i in range(index,len(arreglo)-1):
            arreglo[i] = arreglo[i+1]
        arreglo[-1] = -1
        print("Elemento eliminado exitosamente.")

def randarray(length:int):
    return array([randint(1,100000) for i in range (length)])

class act:
    def __init__(self):
        arr = None
        while True:
            match int(input("""
Ingresa una de las siguientes opciones:
1.- Crear un arreglo de 100 espacios con valores aleatorios
2.- Imprimir el arreglo
3.- Buscar un numero en el arreglo
4.- Eliminar un numero del arreglo
5.- Salir
                """)):
                case 1:
                    arr = randarray(100)
                    print("Arreglo creado exitosamente.")
                case 2:
                    print(arr)
                case 3:
                    index = search(arr,int(input("Ingresa un numero: ")))
                    print(f"El indice del valor es: {index}" if index != -1 else "")
                case 4:
                    remove(arr,int(input("Ingresa un numero: ")))
                case 5:
                    print("Saliendo...")
                    return



if __name__ == "__main__":
    act()