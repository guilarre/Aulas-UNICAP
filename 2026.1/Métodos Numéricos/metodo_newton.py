import math
from decimal import Decimal

def f(x):
    return x - ((x*round(math.log(x), 4)-1)/(1+round(math.log(x), 4)))

x = float(input("Digite o x inicial: "))
xi = None
i = 0

while True:
    i += 1
    xi = round(f(x), 4)
    # Condição de parada:
    if round(math.fabs(xi - x), 4) <= 1e-3:
        # colocando em notação científica a cond. de parada
        print(f"x{i} =", xi, "condicao de parada =", '{:.2E}'.format(Decimal(round(math.fabs(xi - x), 4))))
        break
    else:
        x = xi
        print(x)

print("Foram", i, "iterações")
