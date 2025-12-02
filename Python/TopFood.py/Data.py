


meseros, menu = cargar_datos()
mesas: dict[int, c.Mesa] = {}

class Data_base():

    def __guardar_datos(meseros: dict,menu: dict) -> None:
        with open("Datos.dat", "wb") as f:
            pickle.dump((meseros,menu), f)
    
    def __cargar_datos() -> tuple[dict, dict]:
        try:
            with open("Datos.dat", "rb") as f:
                meseros,menu = pickle.load(f)
                return meseros,menu
        except (FileNotFoundError, EOFError):
            return {}, {}

    def __init__(self):
        self._meseros, self._menu = cargar_datos()

    def 