def busqueda_binaria(arreglo:list, value):
    min = 0
    max = len(arreglo)-1
    while min<=max :
        index = int((max+min)/2)
        place = arreglo[index]
        if place == value : 
            return index
        elif place > value :
            max = index-1
        else : 
            min = index+1
    return -1
print(busqueda_binaria([1,2,3,4,5,6,7,8,9],8))