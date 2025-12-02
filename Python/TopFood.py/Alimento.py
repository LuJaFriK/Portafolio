from abc import ABC as abstract
import data

class Alimento(abstract):
    def __init__(self, nombre: str, costo: float, comentario: str, existencia: bool):
        self._codigo = str(randint(10000))
        self._nombre = nombre
        self._costo = costo
        self._comentario = comentario or ''
        self._existencia = existencia

    @property
    def codigo(self):
        return self._codigo
    
    @property
    def nombre(self) -> str:
        return self._nombre

    @nombre.setter
    def nombre(self,nombre:str):
        if isinstance(nombre,str):
            self._nombre = nombre
        else:
            raise ValueError("Type error") 
    
    @property
    def costo(self) -> float:
        return self._costo

    @costo.setter
    def costo(self,costo:float) -> None:
        if isinstance(costo,float):
            self._costo = costo
        else:
            raise ValueError("Type error") 

    @property
    def comentario(self) -> str:
        return self._comentario
    
    @comentario.setter
    def comentario(self,comentario:str) -> None:
        if isinstance(comentario,str):
            self._comentario = comentario
        else:
            raise ValueError("Type error") 

    
    def detalles(self) -> str:
        return f"{self._nombre}  =======  ${self._costo}"

    def __str__(self) -> str:
        return (f"Nombre: {self._nombre}\nPrecio: ${self._costo}\nComentarios: {self._comentario}")

    def __repr__(self) -> str:
        return (f"Mesero [Nombre: {self._nombre}\nPrecio: ${self._costo}\nComentarios: {self._comentario}]")