from typing import Optional
from Alimento import Alimento
from Cafe import Cafe
from Snack import Snack
from Mesa import Mesa
from Mesero import Mesero
from datetime import datetime
import pickle

class TopFoodLogic:
    def __init__(self):
        self.meseros, self.menu = self.cargar_datos()
        self.mesas = {}

    def guardar_datos(self) -> None:
        with open("Datos.dat", "wb") as f:
            pickle.dump((self.meseros, self.menu), f)

    def cargar_datos(self) -> tuple[dict, dict]:
        try:
            with open("Datos.dat", "rb") as f:
                meseros, menu = pickle.load(f)
                return meseros, menu
        except (FileNotFoundError, EOFError):
            return {}, {}

    def login(self, mesero_id: int, password: int) -> Optional[Mesero]:
        if mesero_id in self.meseros and self.meseros[mesero_id].log(password):
            return self.meseros[mesero_id]
        return None

    def crear_mesero(self, mesero_id: int, nombre: str, password: int) -> bool:
        if mesero_id in self.meseros:
            return False  # Mesero already exists
        self.meseros[mesero_id] = Mesero(nombre, password)
        self.guardar_datos()
        return True

    def eliminar_mesero(self, mesero_id: int) -> bool:
        if mesero_id in self.meseros:
            del self.meseros[mesero_id]
            self.guardar_datos()
            return True
        return False

    def set_existencia(self, producto: str, existe: bool) -> bool:
        if producto in self.menu:
            self.menu[producto].existencia = existe
            self.guardar_datos()
            return True
        return False

    def crear_alimento(self, tipo: str, nombre: str, costo: float, porcion: Optional[int] = None) -> bool:
        if nombre in self.menu:
            return False  # Alimento already exists

        if tipo == "Snack" and porcion is not None:
            self.menu[nombre] = Snack(nombre, costo, '', True, porcion)
        elif tipo == "Cafe":
            self.menu[nombre] = Cafe(nombre, costo, '', True)
        else:
            return False # Invalid type
        
        self.guardar_datos()
        return True

    def get_menu_items_by_type(self, tipo: str) -> list[Alimento]:
        items = []
        for alimento in self.menu.values():
            if tipo == "Snack" and isinstance(alimento, Snack):
                items.append(alimento)
            elif tipo == "Cafe" and isinstance(alimento, Cafe):
                items.append(alimento)
        return items

    def asignar_mesa(self, mesero: Mesero, numero_mesa: int) -> bool:
        if numero_mesa in self.mesas:
            return False # Mesa already exists
        self.mesas[numero_mesa] = Mesa(mesero, True)
        return True

    def hacer_pedido(self, numero_mesa: int, alimento: Alimento, cantidad: int, comentario: str) -> bool:
        if numero_mesa in self.mesas and self.mesas[numero_mesa].activo:
            pedido = self.menu[alimento.nombre]
            if isinstance(pedido, Cafe):
                # For simplicity, we'll use default cafe settings for now.
                # In a real GUI, you'd have widgets to configure this.
                pass
            elif isinstance(pedido, Snack):
                 # For simplicity, we'll use default snack settings for now.
                pass
            pedido.comentario = comentario
            self.mesas[numero_mesa].agregar_pedido(pedido, cantidad)
            return True
        return False
    
    def get_mesas_by_mesero(self, mesero: Mesero) -> dict[int, Mesa]:
        return {num: mesa for num, mesa in self.mesas.items() if mesa.mesero == mesero}

    def cerrar_cuenta(self, numero_mesa: int) -> Optional[str]:
        if numero_mesa in self.mesas and self.mesas[numero_mesa].activo:
            self.mesas[numero_mesa].activo = False
            return self.generar_ticket(self.mesas[numero_mesa], numero_mesa)
        return None

    def generar_ticket(self, mesa: Mesa, numero: int) -> str:
        date = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        ticket_content = "=========TICKET=========\n"
        ticket_content += f"{date}\n"
        ticket_content += f"Mesa: {numero}\n"
        ticket_content += f"Mesero: {mesa.mesero}\n"
        ticket_content += "Nombre  =========   Costo\n"
        for item in mesa.pedido:
            ticket_content += f"{item.detalles()}\n"
        ticket_content += f"Subtotal: ---------- ${mesa.total}\n"
        ticket_content += f"IVA (16%): --------- ${mesa.total * 0.16}\n"
        ticket_content += f"Total: ------------- ${mesa.total * 1.16}\n"
        ticket_content += "=========================\n"
        
        # Save ticket to a temp file
        with open(f"Mesa_{numero}_temp.txt", "w") as ticket_file:
            ticket_file.write(ticket_content)
            
        return ticket_content