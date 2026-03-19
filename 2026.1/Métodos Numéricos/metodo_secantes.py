import math

# Função da questão
def f(x):
    return x**2 + x - 6

def fsecante(a, b):
    return (a*f(b) - b*f(a)) / (f(b) - f(a))

# a == x_i-1; b == x_i
a = 1.5
b = 1.7
c = None

# Nº de iterações
i = 0

while (True):
    # c == x_i+1
    c = round(fsecante(a, b), 6) # único round deve acontecer aqui (de acordo com ref do prof)

    print(f"#{i}: x_i+1 = {c}\tx_i = {b}\tx_i-1 = {a}")

    if round(math.fabs(f(c)), 6) < 1e-4 or math.fabs(c - b) < 1e-3: # Condição da questão
        break

    a = b
    b = c
    i += 1

