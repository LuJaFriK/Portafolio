class Mesero:
    def __init__(self,nombre: str,password: int):
        self.nombre = nombre
        self._password = password

    def __str__(self):
        return (f"Nombre: {self.nombre}")

    def log(self,pswrd: int):
        return (self._password == pswrd)