jerarquia = {'+': 1,'-': 1,'*': 2,'/': 2}

def es_operador(token):
    return token in jerarquia

def infija_a_postfija(expresion_infija):

    pila_operadores = []
    salida_postfija = []

    tokens = expresion_infija.split()

    for token in tokens:
        if token.isalnum():
            salida_postfija.append(token)
        
        elif token == '(':
            pila_operadores.append(token)
            
        elif token == ')':
            while pila_operadores and pila_operadores[-1] != '(':
                salida_postfija.append(pila_operadores.pop())
            
            if pila_operadores and pila_operadores[-1] == '(':
                pila_operadores.pop()
            
        elif es_operador(token):
            while (pila_operadores and pila_operadores[-1] != '(' and 
                   jerarquia.get(pila_operadores[-1], 0) >= jerarquia[token]):
                salida_postfija.append(pila_operadores.pop())
            
            pila_operadores.append(token)

    while pila_operadores:
        salida_postfija.append(pila_operadores.pop())

    return ' '.join(salida_postfija)

expresion1 = "A + B * C"
expresion2 = "( A + B ) * C / D"
expresion3 = "3 * ( 4 + 2 ) - 1"

print(f"{expresion1} -> {infija_a_postfija(expresion1)}")
print(f"{expresion2} -> {infija_a_postfija(expresion2)}")
print(f"{expresion3} -> {infija_a_postfija(expresion3)}")