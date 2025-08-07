
expresiones_unidades :dict = {0:"En punto",1:"uno",2:"dos",3:"tres",4:"cuatro",5:"cinco",6:"seis",7:"siete",8:"ocho",9:"nueve"}

expresiones_decenas: dict = {10:"diez",11:"once",12:"doce",15:"cuarto",20:"veinte",30:"media",40:"cuarenta",45:"tres cuartos",50:"cincuenta",}

def hour_to_twelve_format(hora:tuple) -> tuple[str, str]:
    hora_entero: int = int(hora[0]+hora[1])
    if hora_entero > 12:
        hora_entero -= 12
    hora_str:str = str(hora_entero)
    return (hora_str[0],hora_str[1])

def round_minutes(minutos:tuple):
    if minutos[1] % 5 != 0:




def conversor_horario(hora:str)->str:
    format_check = lambda hora: len(hora) == 5 and hora[2] == ':' and int(hora[0])<3 and int(hora[3])<6 and
    
    if not format_check(hora):raise ValueError("El formato no es correcto.")
    else:
        hora_en_palabras:str = "Son las"
        horas:tuple = (hora[0],hora[1])
        minutos:tuple = (hora[3],hora[4])
        horas = hour_to_twelve_format(horas)

    return hora_en_palabras


conversor_horario("29:34")