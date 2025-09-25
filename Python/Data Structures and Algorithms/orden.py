import operaciones as op



expresion_stack: dict[list[str],list[float]] = {'':[],[]}

result: list[str] = []

expresion: str = input("Ingresa la expresion a convertir: ")

