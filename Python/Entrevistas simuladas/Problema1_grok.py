def devolver_indices(lista:list,resultado)->list:
    diccionario:dict = {}
    for i in range(len(lista)):
        current = lista[i]
        complemento = resultado-current
        if complemento in diccionario:
            return [diccionario[complemento],i]
        
        diccionario[current] = i

lista = [1,3,5,6,7,9]
print(len(lista))
print(devolver_indices(lista,9))
