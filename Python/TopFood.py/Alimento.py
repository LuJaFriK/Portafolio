from abc import ABC as abstract

class Alimento(abstract):
    def __init__(self, nombre: str, costo: float, comentario: str, existencia: bool):
        self._nombre = nombre
        self._costo = costo
        self._comentario = comentario or ''
        self._existencia = existencia
    
    @property
    def costo(self) -> float:
        return self._costo

    @costo.setter
    def costo(self,costo) -> None:
        self._costo = costo

    @property
    def comentario(self) -> str:
        return self._comentario
    
    @comentario.setter
    def comentario(self,comentario) -> None:
        self._comentario = comentario

    
    def detalles(self) -> str:
        return f"{self._nombre}  =======  ${self._costo}"

    def __str__(self) -> str:
        return (f"Nombre: {self._nombre}\nPrecio: ${self._costo}\nComentarios: {self._comentario}")