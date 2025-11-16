def sin_repetir(cadena:str) -> int:
    lista = [0] 
    substring = ""
    counter = lista[0]
    for car in cadena:
        if car in substring:    
            substring = ""
            lista.append(0)
            counter = lista[-1]
        else:
            counter +=1
        substring += car
    return counter