opciones = """
Ingresa una de las opciones:
1. Sumar
2. Restar
3. Multiplicar
4. Dividir
5. Salir
"""
while True:
    try:
        opc = int(input(opciones))
        if opc == 5:
            print("Saliendo...")
            break
        if opc>0 and opc<6:
            num1 = float(input("Ingresa el primer numero: \n"))
            num2 = float(input("Ingresa el segundo numero: \n"))
            print('Tu resultado es:')
            match opc:
                case 1:
                    print(num1+num2)
                case 2:
                    print(num1-num2)
                case 3:
                    print(num1*num2)
                case 4:
                    if num2 == 0:
                        print("No es posible dividir entre 0")
                    else:
                        print(num1/num2)
    except ValueError:
        print("Error. Caracter no numerico")


