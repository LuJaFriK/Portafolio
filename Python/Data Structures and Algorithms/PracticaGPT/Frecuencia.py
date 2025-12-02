def frecuencia_caracteres(cadena:str):
    mapa:dict = {}
    for char in cadena:
        if char in mapa:
            mapa[char]+=1
        else:
            mapa[char] = 1
    return mapa

print(frecuencia_caracteres("HolaHolaHola"))