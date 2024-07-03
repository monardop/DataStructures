from random import randint

nombres = [
    "Alejandro", "Beatriz", "Carlos", "Diana", "Eduardo", "Fernanda", 
    "Gabriel", "Hugo", "Isabel", "Javier", "Karen", "Luis", 
    "Monica", "Nicolas", "Olivia", "Pablo", "Raquel", "Santiago", 
    "Teresa", "Victor", "Ana", "Benjamin", "Clara", "David", 
    "Elena", "Felipe", "Gustavo", "Hector", "Irene", "Jorge", 
    "Laura", "Marcos", "Natalia", "Oscar", "Patricia", "Ricardo", 
    "Sara", "Tomas", "Valeria", "Ximena"
]

ids_nombre = []
while(len(ids_nombre) < 20):
    x = randint(1,29)
    if x not in ids_nombre:
        ids_nombre.append(x)

with open("operators.txt", "w") as fp:
    for i in range(20):
        fp.write(f"id nro.: {ids_nombre[i]}\n")

