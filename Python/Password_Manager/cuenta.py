from cryptography.fernet import Fernet

class entrada:
    def __init__(self,user_name: str) -> None:
        self.user_name = input("Ingresa el usuario de la cuenta:\n")
        self.__code = self.crear_contraseña()

    def crear_contraseña(self)-> str:
        while True:
            pass1: str = input("Ingresa tu contraseña:\n")
            pass2: str = input("Ingresa tu contraseña nuevamente:\n")
            if pass1 == pass2:
                if self.is_safe(pass1):
                    return pass1
            else:
                print("Las contraseñas no coinciden, intenta nuevamente.")

    def __str__(self) -> str:
        return '*' * len(self.__code)
   
    def is_safe(self,pass1:str) -> bool:
        requirements: dict[str, list[str]] = {
        "Mayusculas": [chr(i) for i in range(65, 91)],            # A-Z
        "Minusculas": [chr(i) for i in range(97, 123)],           # a-z
        "Numeros":     [str(i) for i in range(10)],               # 0-9 como strings
        "Simbolos":   list("!@#$%^&*()-_+=")                      # símbolos deseados
        }
        SAFE: bool = True
        comprobaciones: dict[str, bool] = {key: False for key in requirements}

        for val in pass1:
            for categoria in (list(requirements)):
                if val in requirements[categoria]:
                    comprobaciones[categoria] = True
                    break
                    
        for cat,val in comprobaciones.items(): 
            if val == False:
                print(f"La contraseña carece de {cat.lower()}.") 
                SAFE = False

        if len(pass1) < 8: 
            print("La contraseña debería ser de al menos 8 caracteres para ser segura.") 
            SAFE = False

        print(f"La contraseña es "+("segura." if SAFE else "insegura."))
        return SAFE 

    def login(self,attempt: str)->bool:
        return self.__code == attempt