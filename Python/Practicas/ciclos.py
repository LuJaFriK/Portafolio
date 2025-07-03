for i in range (1,6):
    print(i)
viejas = ["Alyson","Renata","Michelle","Araceli"]
for vieja in viejas:
    if vieja=="Renata":
        continue
    print(vieja)
maicol = 'gay'
while maicol=='gay':
    print('maicol gay')
    break
#En python los indices negativos en una lista sirven para contar de arriba a abajo
viejas.append("Sexo")
print(viejas[-1])
viejas.insert(0,"Silvia")
viejas.remove("Sexo")
viejas.sort()
print(viejas)
lista = []
a = ""
while a != "0":
    a = input("Inserta un nombre de una persona (0 para terminar)")
    if a!="0":
        lista.append(a)
print(lista)

