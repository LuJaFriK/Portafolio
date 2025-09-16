from random import randint
import time
import tracemalloc

def search(lista: list, value: int) -> int:
    for i in range(len(lista)):
        if lista[i] == value:
            return i
    return -1

# Iniciar medición de memoria
tracemalloc.start()

# Medir tiempo de ejecución
start_time = time.perf_counter()

# Paso 1 y 2: Crear lista con 50000 espacios
lista = [randint(1, 10000) for _ in range(50000)]

# Paso 3: Imprimir tamaño de la lista (en lugar de imprimir todo)
print(lista)

# Paso 4: Método de búsqueda
print("Índice de 3456:", search(lista, 3456))

# Paso 5: Buscar valor
valor = lista[67]
print("Valor en posición 67:", valor)

# Paso 6: Eliminar el valor en la posición 67
lista.remove(valor)

# Paso 7: Reimprimir tamaño de la lista
print(lista)

# Medir tiempo final
end_time = time.perf_counter()

# Obtener memoria utilizada
current, peak = tracemalloc.get_traced_memory()
tracemalloc.stop()

print(f"\n⏱ Tiempo de ejecución: {(end_time - start_time) * 1000:.3f} ms")
print(f" Memoria actual usada: {current / 1024:.2f} KB")
print(f" Pico máximo de memoria: {peak / 1024:.2f} KB")
