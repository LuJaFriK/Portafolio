from math import sqrt #Importa solo el modulo sqrt de la biblioteca math
# si quisiera importar toda la biblioteca math, tendria que escribir math.sqrt()
print(sqrt(25))

import datetime
fecha = datetime.datetime.now()
print(fecha)

import random

print(f"Numero aleatorio: {random.randint(1,10)}")

from Paquete import modulo

modulo.hola()