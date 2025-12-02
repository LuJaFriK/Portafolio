def parentesis_balanceados(cadena:str):
    parentesis = []
    mapa = {'(':')','[':']','{':'}'}
    for char in cadena:
        if char in mapa.keys():
            parentesis.append(char)
        elif char in mapa.values():
            if mapa.get(parentesis.pop()) != char:
                return False    
    return len(parentesis) == 0

print(parentesis_balanceados("({[]})"))
print(parentesis_balanceados("({[]}"))