
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

    i=0
    numbers = 0
    for char in expresion:
        if char in ('*','/','+','-'):
            operadores.append(char)
        try:
            n = float(char)
            operandos.append(char)
        except ValueError:
            pass

        if len(operandos)>1:
            postorden+=operandos.pop()
            postorden+=operandos.pop()
            postorden+=operadores.pop()

    print(operadores)
    print(operandos)
    return postorden



h = ('1+3-4')

print(con(h))

