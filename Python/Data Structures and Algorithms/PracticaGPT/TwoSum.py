def suma_de_dos(arreglo:list,result:int):
    valores:dict = {}
    for i in range(len(arreglo)):
        resto = result-arreglo[i]
        if resto in valores:
            return [i,valores[resto]]
        else:
            valores[arreglo[i]] = i


arreglo = [1,2,3,4,5,6,7,8,9]
resultado = 17

print(suma_de_dos(arreglo,resultado))

