from typing import Optional
from Alimento import Alimento ; from Cafe import Cafe ; from Snack import Snack
from Mesa import Mesa ; from Mesero import Mesero
from datetime import datetime ; import pickle

def guardar_datos(meseros: dict,menu: dict) -> None:
        with open("Datos.dat", "wb") as f:
            pickle.dump((meseros,menu), f)
    
def cargar_datos() -> tuple[dict, dict]:
    try:
        with open("Datos.dat", "rb") as f:
            meseros,menu = pickle.load(f)
            return meseros,menu
    except (FileNotFoundError, EOFError):
        return {}, {}

def login(meseros: dict) -> Optional[Mesero]:
        mesero = None
        index = int(input("Ingresa el codigo de mesero: "))
        if index in meseros:
            for i in range (1,3):
                password = int(input(f"Ingresa la contraseña para {meseros[index].nombre}: "))
                if meseros[index].log(password):
                    mesero = meseros[index]
                    break
                if i == 3:
                    print("Demasiados intentos fallidos.")
                    print("Desea crear un mesero nuevo?")
                    condicion = input("1. Si  2. No")
                    if condicion == '1':
                        crear_mesero(meseros)
                    break
            else: print("Contraseña incorrecta.")
        else: print(f"No existe un mesero con el codigo: {index}")
        return mesero
    
def crear_mesero(meseros: dict) -> None:
        while True:
            index = int(input("Ingresa el codigo del nuevo mesero: "))
            if index in meseros:
                print("Codigo ya registrado.")
            else: 
                nombre = input("Ingresa el nombre del Mesero: ")
                while True:
                    pass1 = int(input("Ingresa tu contraseña: "))
                    pass2 = int(input("Ingresa tu contraseña nuevamente: "))
                    if pass1 == pass2:
                        meseros[index] = Mesero(nombre,pass1 or pass2)
                        return
                    else: print("Las contraseñas no coinciden, intentelo nuevamente.")
                
    
def eliminar_mesero(meseros: dict)-> None:
        for mesero in meseros: 
            print(mesero)
        codigo = int(input("Ingresa el codigo del mesero que deseas eliminar: "))
        if codigo in meseros:
            del meseros[codigo]
            print(f"El mesero con codigo {codigo} ha sido eliminado exitosamente.")
        else: print("El mesero no ha sido encontrado.")
    
def set_existencia(menu: dict,existe: bool) -> None:
        producto = input("Ingresa el nombre del producto: ")
        if producto in menu:
            menu[producto].existencia = existe
            dada = "Si" if existe else "No"
            print(f"Prodcuto dado de {dada} con exito.")
        else: print("El producto no está registrado.")
    
def juntar_mesas(mesero: Mesero, mesas: dict) -> None:
        print("Ingresa los numeros de las mesas: ")
        mesa1: int = int(input("Ingresa el numero de la nueva mesa:"))
        mesa2: int = int(input("Ingresa el numero de la segunda mesa:"))
        if (mesa1 in mesas and mesa2 in mesas) and (mesas[mesa1].mesero == mesero or mesas[mesa2].mesero == mesero):
            new_mesa = Mesa(mesero,True)
            for mesa in (mesa1,mesa2):
                for i in range(0,len(mesas[mesa].pedido)):
                    new_mesa.agregar_pedido(mesas[mesa].pedido[i],1)
            while True:
                new_mesa_index = int(input("Ingresa el numero nuevo de la mesa: "))
                if new_mesa_index == mesa1 or new_mesa_index == mesa2 or new_mesa_index not in mesas:
                    mesas[new_mesa_index] = new_mesa
                    break
                else: print("El numero de mesa está ocupado")

def crear_alimento(menu: dict) -> None:
        tipo = int(input("Elige el tipo de alimento:\n1.Snack\n2.Cafe\n"))
        if tipo == 1:
            nombre = input("Ingresa el nombre del Snack: ")
            if nombre not in menu:
                costo = float(input("Ingresa su costo: "))
                porcion = int(input("Ingresa el tamaño del Paquete / Porcion Grande:"))
                menu[nombre] = Snack(nombre,costo,'',True,porcion)
                print(menu[nombre])
            else: print("El Snack ya existe.")
        elif tipo == 2:
            nombre = input("Ingresa el nombre del Cafe: ")
            if nombre not in menu:
                costo = float(input("Ingresa su costo: "))
                menu[nombre] = Cafe(nombre,costo,'',True)
            else: print("El Cafe ya existe.")
        else: print("Opcion no válida.")
    
def menu_mesero(meseros: dict,menu: dict, mesas: dict) -> None:
        pedir_numero = lambda: int(input("Ingresa el numero de la mesa: "))
        usuario: Mesero | None = login(meseros)
        if usuario == None: return
        menumesero = f"""Bienvenido {usuario.nombre}, ingresa una de las opciones a continuacion:
        1.- Abrir cuenta.
        2.- Visualizar mesas.
        3.- Agregar productos.
        4.- Cerrar una cuenta.
        5.- Eliminar una cuenta.
        6.- Juntar cuentas.
        7.- Salir.
        """
        while True:
            match int(input(menumesero)):
                case 1:
                    asignar_mesa(usuario,mesas,menu)
                case 2:
                    for numero, mesa in mesas.items():
                        if mesa.mesero == usuario:
                            print(f"Mesa {numero}: {mesa}")
                case 3:
                    numero_mesa = pedir_numero()
                    if (mesas[numero_mesa].mesero == usuario) and mesas[numero_mesa].activo:
                        hacer_pedido(mesas[numero_mesa],usuario,menu)
                case 4:
                    numero_mesa = pedir_numero()
                    if numero_mesa in mesas and mesas[numero_mesa].mesero == usuario:
                        ticket(mesas[numero_mesa],numero_mesa);mesas[numero_mesa].activo = False
                    else: print("La mesa no ha sido encontrada o no pertenece al mesero.")
                case 5:
                    numero_mesa = pedir_numero()
                    if numero_mesa in mesas and mesas[numero_mesa].mesero == usuario:
                        if mesas[numero_mesa].activo == False:
                            del mesas[numero_mesa]
                        else: print("La mesa sigue activa y no puede eliminarse")
                    else: print("La mesa no ha sido encontrada o no pertenece al mesero.") 
                case 6:
                    juntar_mesas(usuario, mesas)
                case 7:
                    return
                case _:
                    print("Opcion no valida.")

def mostrar_menu(menu: dict) -> None:

    for clase_tipo in (Snack,Cafe):
        print("\n======================")
        print(f"Categoría:"+ ("Snack" if clase_tipo == Snack else "Cafe"))
        print("======================")

        for alimento in menu.values():
            if isinstance(alimento, clase_tipo):
                print("----------------------")
                print(alimento.detalles())
                print("----------------------")

    
def hacer_pedido(mesa: Mesa,mesero: Mesero, menu: dict) -> None:
        if mesa.mesero != mesero: return
        comanda: list[Alimento] = []
        contador = 0
        while True: 
            mostrar_menu(menu)
            nombre = input("Ingresa el nombre del alimento: ")
            if nombre in menu:
                pedido: Alimento = menu[nombre]
                contador = 0
            else:
                contador +=1 
                if contador > 2 :
                    print("Demasiados intentos fallidos.")
                    return
                continue
            if isinstance(pedido,Cafe): pedido = configurar_cafe(pedido)
            elif isinstance(pedido,Snack): pedido = configurar_snack(pedido)
            else: 
                print("El alimento ha sido mal implementado, eliminalo del menu y configuralo nuevamente.")
                return
            pedido.comentario = input("Realizar un comentario: ")
            cafe_postre = "cafes" if isinstance(pedido,Cafe) else "postres"
            cantidad = int(input(f"Cantidad de {cafe_postre} iguales:"))
            mesa.agregar_pedido(pedido,cantidad)
            for i in range(1,cantidad): comanda.append(pedido)
            otro = """¿Desea ingresar otro pedido?
                1. Sí
                2. No
                """
            if int(input(otro)) != 1: 
                for Tipo in (Snack,Cafe):
                    print("========================")
                    print("Snack:" if Tipo == Snack else "Cafes:")
                    for pedido in comanda:
                        if isinstance(pedido,Tipo):
                            print(pedido)
                    print("========================")
                return
            
def configurar_cafe(cafe: Cafe) -> Cafe:
        menucafeteria = (
            """
            Cafeina:
            1. Sí
            2. No
            """,
            """
            Hielo:
            1. Frío
            2. Caliente         
            """)
        if int(input(menucafeteria[0])) == 1: cafe.cafeina = True
        else: cafe.cafeina = False
        if int(input(menucafeteria[1])) == 1: cafe.hielo = True
        else: cafe.hielo = False
        cafe.set_milk(int(input("Ingresa el tipo de leche que prefieras: \n"+cafe.printMilkList())))

        return cafe
    
def configurar_snack(snack: Snack) -> Snack:
        ind_paquete = """
        1. Porcion individual
        2. Porcion Completa
        """
        if int(input(ind_paquete)) == 2: snack.alternar_individual(False)
        else: snack.alternar_individual(True)
        return snack

def asignar_mesa(mesero: Mesero,mesas: dict,menu: dict)-> None:
        numero = int(input("Ingresa el numero de la mesa: "))
        if numero in mesas:
            print("La mesa ya existe."); return
        else: 
            mesas[numero] = Mesa(mesero,True)
            ordenar = """
                Desea tomar la orden?
                1. Si       2. No
                """
            match int(input(ordenar)):
                case 1: hacer_pedido(mesas[numero],mesero,menu)
                case _:return
    
def ticket(mesa: Mesa, numero: int)-> None:
    date: str = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    with open(f"Mesa {numero}_temp.txt","w") as ticket:
        ticket.write("=========TICKET=========")
        ticket.write(date)
        ticket.write(f"Mesa: {numero}")
        ticket.write(f"Mesero: {mesa.mesero}")
        ticket.write("Nombre  =========   Costo")
        for alimento in mesa.pedido:
            ticket.write(alimento.detalles)
        ticket.write(f"Subtotal: ---------- ${mesa.total}")
        ticket.write(f"IVA (16%): --------- ${(mesa.total)*.16}")
        ticket.write(f"Total: ------------- ${(mesa.total)*1.16}")
        ticket.write("=========================")  

class Comandera:

    def __init__(self) -> None:
        meseros, menu = cargar_datos()
        mesas: dict[int, Mesa] = {}
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
                    menu_mesero(meseros,menu,mesas)
                case 2:
                    crear_mesero(meseros)
                case 3:
                    eliminar_mesero(meseros)
                case 4:
                    crear_alimento(menu)
                case 5:
                    set_existencia(menu, False)
                case 6:
                    set_existencia(menu, True)
                case 7:
                    guardar_datos(meseros,menu)
                    return
                case _:
                    print("Error. Opcion no valida")




if __name__ == "__main__":
    Comandera()








