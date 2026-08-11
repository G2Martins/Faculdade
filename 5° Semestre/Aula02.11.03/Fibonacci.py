# Repetição While EM PY
n1 = 0
n2 = 1
limite = int(input("Quantas Termos de Fibonnaci voce deseja? "))
contador = 3

while contador <= limite:
    n3 = n1 + n2
    print(f"{n3} = {n1} + {n2}")
    n1 = n2
    n2 = n3
    contador += 1