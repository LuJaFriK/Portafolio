def invertir(lista:list):
    izq = 0
    der = len(lista)-1
    while izq < der:
        lista[izq],lista[der] = lista[der],lista[izq]
        izq+=1 ;der-=1
    return lista
    

lista = invertir([1,2,3,4,5,6,7,8,9,10])

print(lista)