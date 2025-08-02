from Alimento import Alimento

class Snack(Alimento):
    def __init__(self, nombre: str, costo: float, comentario: str, existencia: bool, porcion: int):
        super().__init__(nombre, costo, comentario, existencia)
        self.individual = True
        self.porcion_cantidad = porcion

    def get_costo(self):
        new_costo = super().get_costo()
        if (not self.individual):
            new_costo *= (self.porcion_cantidad-2)
        return new_costo

    def alternar_individual(self,valor: bool):
        self.individual = valor

    def __str__(self):
        return (f"Nombre: {self.nombre}\nPorcion: "+("Individual" if self.individual else "Grande")+
        f"\nPrecio: {self.get_costo()}\nComentarios: {self.comentario}")
    