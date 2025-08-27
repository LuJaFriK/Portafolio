# Manera clasica de trabajar con archivos de texto

def leer_archivo(nombre):
    try:
        archivo = open(nombre,"r")
        print(archivo.read())
    except FileNotFoundError:
        print("Nada, no hay, no existe")
    finally:
        archivo.close()
    
def escribir_archivo(nombre):
    archivo = open(nombre,"w")
    archivo.write(input("Escribele algo we"))
    archivo.close()

# Manera tipo try con resources

def leer(nombre):
    try:
        with open(nombre, "r") as archivo:
            contenido = archivo.read()
            print(contenido)
    except FileNotFoundError:
        print("Nada, no hay, no existe")
    finally:
        archivo.close()

def escribir(nombre):
    with open(nombre, "w") as archivo:
        archivo.write(input("Escribele algo we"))
        archivo.close()