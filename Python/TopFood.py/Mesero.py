class Mesero:
    def __init__(self,nombre: str,password: int) -> None:
        self.nombre = nombre
        self._password = password

    def __str__(self) -> str:
        return (f"Nombre: {self.nombre}")

    def log(self,pswrd: int) -> bool:
        return (self._password == pswrd)