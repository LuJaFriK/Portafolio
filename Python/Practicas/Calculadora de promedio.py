def promedio(calificaciones: list[float]) -> float:
    if len(calificaciones) == 0: return 0
    sumatoria = 0.0
    for calificacion in calificaciones:
        sumatoria += calificacion
    return sumatoria / len(calificaciones)

def pedir_calificaciones() -> list[float]:
    between = lambda min,max,value: value <=max and value >=min
    calificaciones: list[float] = []
    while True:
        calificacion: float = float(input("Ingresa la calificacion del estudiante: (-1 para terminar)\n"))
        if calificacion != -1.0:
            if between(0,100,calificacion):
                calificaciones.append(calificacion)
            else:
                print("Calificacion no valida, intente de nuevo.")
        else:
            break
    return calificaciones

print(promedio(pedir_calificaciones()))
