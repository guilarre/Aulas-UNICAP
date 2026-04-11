import math
# # from decimal import Decimal
#
# def f(x):
#     return x - (x * math.log(x) - 1) / math.log(x) + 1
#
# x = float(input("Digite o x inicial: "))
# xi = None
# i = 0
#
# while True:
#     i += 1
#     xi = round(f(x), 4)
#     # Condição de parada:
#     if math.fabs(xi - x) <= 1e-3:
#         # colocando em notação científica a cond. de parada
#         # print(f"x{i} =", xi, "condicao de parada =", '{:.2E}'.format(Decimal(round(math.fabs(xi - x), 4))))
#         print(f"x{i} =", xi)
#         break
#     else:
#         x = xi
#         print(x)
#
# print("Foram", i, "iterações")

def f(x):
    return x * math.log(x) - 1

def df(x):
    return math.log(x) + 1

x = float(input("Digite o x inicial: "))
xi = None
i = 0

while True:
    xi = round(x - f(x)/df(x), 4)
    # Condição de parada:
    if math.fabs(xi - x) <= 1e-3:
        # colocando em notação científica a cond. de parada
        # print(f"x{i} =", xi, "condicao de parada =", '{:.2E}'.format(Decimal(round(math.fabs(xi - x), 4))))
        print(f"x{i} =", xi)
        break
    else:
        x = xi
        print(x)
    i += 1

print("Foram", i, "iterações")
