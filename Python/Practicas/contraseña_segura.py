class password:
    def __init__(self,code: str) -> None:
        self._code = code
        self._requirements = {
        "Mayusculas": [chr(i) for i in range(65, 91)],            # A-Z
        "Minusculas": [chr(i) for i in range(97, 123)],           # a-z
        "Numeros":     [str(i) for i in range(10)],               # 0-9 como strings
        "Simbolos":   list("!@#$%^&*()-_+=")                      # símbolos deseados
        }

        self._safe: bool = self.check_safety()

    def __str__(self) -> str:
        return '*' * len(self._code)
   
    def check_safety(self) -> bool:
        SAFE: bool = True
        comprobaciones: dict[str, bool] = {key: False for key in self._requirements}

        for val in self._code:
            for categoria in (list(self._requirements)):
                if val in self._requirements[categoria]:
                    comprobaciones[categoria] = True
                    break
                    
        for cat,val in comprobaciones.items(): 
            if val == False:
                print(f"La contraseña carece de {cat.lower()}.") 
                SAFE = False

        if len(self._code) < 8: 
            print("La contraseña debería ser de al menos 8 caracteres para ser segura.") 
            SAFE = False

        print(f"La contraseña es "+("segura." if SAFE else "insegura."))
        return SAFE 

    def login(self,attempt: str)->bool:
        return self._code == attempt

contraseña: password = password(input("Ingresa la contraseña: \n"))



    


        


            







    
