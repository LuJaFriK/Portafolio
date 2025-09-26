
def operar(operador:str,a:float,b:float) :
    match(operador):
        case '+':
            return a+b
        case '-':
            return a-b
        case '*':
            return a*b
        case '/':
            return a/b
    return 0.0
    

def con(expresion:str):
    postorden:str = ''
    operadores:list[str] = []
    operandos:list[str] = []

    numbers = 0
    for char in expresion:
        if char in ('*','/','+','-'):
            operadores.append(char)
        try:
            n = float(char)
            postorden+=char
            numbers+=1
        except ValueError:
            pass

        if numbers>1:
            postorden+=operadores.pop()
            numbers = 0

    print(operadores)
    print(operandos)
    return postorden



h = ('1+3-4')

print(con(h))

