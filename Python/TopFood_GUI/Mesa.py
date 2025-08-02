from Mesero import Mesero
from Alimento import Alimento
class Mesa:
    def __init__(self,mesero: Mesero, activo: bool):
        self.mesero = mesero
        self.activo = activo
        self.pedido = []
        self.total = 0.0
    
    def agregar_pedido(self,alimento: Alimento,cantidad: int):
        for i in range(1,cantidad):
            self.pedido.append(alimento)
            self.total += alimento.get_costo()
    
    def print_pedido(self):
        print("Nombre  ================   Costo")
        for alimento in self.pedido:
            print(alimento.detalles())
        print("===============================")
    
    def __str__(self, numero: int):
        activa = "Si" if self.activo else "No"
        return(f"Mesero encargado: {self.mesero.nombre}\nActiva: {activa}\nTotal actual: {self.total}")