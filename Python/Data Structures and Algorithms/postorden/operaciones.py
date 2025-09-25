class operators:
    def __init__(self,expresion:str) -> None:
        self.__expresion = expresion
        self.__postorden:str = ''
    
    @staticmethod
    def is_operador(char:str)->bool:
        return (char in ('*','/','+','-'))
    
    @staticmethod
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
    
    @staticmethod
    def jerarquia(char:str) -> bool:


