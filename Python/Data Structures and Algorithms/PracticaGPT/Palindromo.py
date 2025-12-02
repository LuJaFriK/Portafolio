def is_palindromo(palabra:str):
    palindromo = "".join(c for c in reversed(palabra))
    return palabra.capitalize() == palindromo.capitalize()

print(is_palindromo("Mororom"))