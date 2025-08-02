from abc import ABC as abstract

class Alimento(abstract):
    def __init__(self, nombre: str, costo: float, comentario: str, existencia: bool):
        self.nombre = nombre
        self._costo = costo
        self.comentario = comentario or ''
        self.existencia = existencia
    
    def set_costo(self,costo) -> None:
        self._costo = costo
        
    def get_costo(self) -> float:
        return self._costo
    
    def detalles(self) -> str:
        return f"{self.nombre}  =======  ${self.get_costo()}"

    def __str__(self) -> str:
        return (f"Nombre: {self.nombre}\nPrecio: ${self.get_costo()}\nComentarios: {self.comentario}")