# pontos para a interpolação
x_pontos = [0, 1, 2, 3, 4]
y_pontos = [-2, 1, 0, -5, 1]

def polinomio_lagrange(indice, x_valores, x_avaliar):
    """
    Calcula o polinômio de Lagrange L_i(x) para um ponto específico.

    Parâmetros:
    - indice: índice i do polinômio L_i
    - x_valores: lista com as coordenadas x dos pontos conhecidos
    - x_avaliar: valor de x onde queremos avaliar L_i(x)

    Retorna: valor de L_i(x_avaliar)
    """
    produto = 1
    n = len(x_valores)

    for j in range(n):
        if j != indice:
            # Multiplica por (x - x_j)/(x_i - x_j)
            produto = produto * (x_avaliar - x_valores[j]) / (x_valores[indice] - x_valores[j])

    return produto

def interpolar_lagrange(x_valores, y_valores, x_avaliar):
    """
    Calcula o polinômio interpolador de Lagrange P(x) em um ponto.
    
    Parâmetros:
    - x_valores: lista com as coordenadas x dos pontos conhecidos
    - y_valores: lista com as coordenadas y dos pontos conhecidos
    - x_avaliar: valor de x onde queremos avaliar P(x)
    
    Retorna: valor de P(x_avaliar)
    """
    soma = 0
    n = len(x_valores)
    
    for i in range(n):
        # P(x) = y_0*L_0(x) + y_1*L_1(x) + ... + y_n*L_n(x)
        soma = soma + y_valores[i] * polinomio_lagrange(i, x_valores, x_avaliar)
    
    return soma

# Exemplo de uso
resultado = interpolar_lagrange(x_pontos, y_pontos, 0.5)
print(f"P(0.5) = {resultado}")

# Testando em todos os pontos conhecidos
# print("\nVerificando os pontos originais:")
# for i in range(len(x_pontos)):
#     valor = interpolar_lagrange(x_pontos, y_pontos, x_pontos[i])
#     print(f"P({x_pontos[i]}) = {valor} (esperado: {y_pontos[i]})")
