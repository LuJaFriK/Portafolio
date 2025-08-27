import Comandera as c
class Interfaz:

    def __init__(self) -> None:
        meseros, menu = c.cargar_datos()
        mesas: dict[int, c.Mesa] = {}
        menus = """
            Ingrese la acción que desea realizar a continuación:
            1.- Iniciar sesión como mesero.
            2.- Registrar un mesero nuevo.
            3.- Eliminar un mesero.
            4.- Ingresar nuevos alimentos.
            5.- Dar de baja un producto.
            6.- Dar de alta un producto.
            7.- Salir del sistema.
            """
        while True:
            
            match int(input(menus)):
                case 1:
                    c.menu_mesero(meseros,menu,mesas)
                case 2:
                    c.crear_mesero(meseros)
                case 3:
                    c.eliminar_mesero(meseros)
                case 4:
                    c.crear_alimento(menu)
                case 5:
                    c.set_existencia(menu, False)
                case 6:
                    c.set_existencia(menu, True)
                case 7:
                    c.guardar_datos(meseros,menu)
                    return
                case _:
                    print("Error. Opcion no valida")




if __name__ == "__main__":
    Interfaz()








