class Objeto:
    
    def __init__(self,nombre,numero):
        self.__nombre = nombre
        self.__numero = numero

    @property
    def nombre(self):
        return f"El nombre del objeto es {self.__nombre}"

    @nombre.setter
    def nombre(self,nombre):
        self.__nombre = nombre

    
    def haceralgo(accion):
        print("Estoy",accion)

    def __str__(self):
        return f"Nombre: {self.__nombre}, edad: {self.__numero}"