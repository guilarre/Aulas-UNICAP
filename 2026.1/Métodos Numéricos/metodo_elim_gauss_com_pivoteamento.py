import numpy as np

def substituicao_regressiva(U, c, tol=1e-12):
    # Resolve Ux = c, assumindo U triangular superior.
    U = U.astype(float).copy()
    c = c.astype(float).copy()
    n = len(c)
    x = np.zeros(n)

    for i in range(n - 1, -1, -1):
        if abs(U[i, i]) < tol:
            raise ZeroDivisionError(f"Pivô nulo ou quase nulo na linha {i}.")
        soma = np.dot(U[i, i+1:], x[i+1:])
        x[i] = (c[i] - soma) / U[i, i]

    return x

def gauss_com_pivoteamento_parcial(A, b, tol=1e-12, mostrar_passos=True):
    # Eliminação de Gauss com pivoteamento parcial.
    A = A.astype(float).copy()
    b = b.astype(float).copy()
    n = len(b)

    for k in range(n - 1):
        linha_pivo = k + np.argmax(np.abs(A[k:, k]))

        if abs(A[linha_pivo, k]) < tol:
            raise ZeroDivisionError(f"Matriz singular ou pivô quase nulo na coluna {k}.")

        if linha_pivo != k:
            A[[k, linha_pivo]] = A[[linha_pivo, k]]
            b[[k, linha_pivo]] = b[[linha_pivo, k]]

            if mostrar_passos:
                print(f"\nTroca de linhas: L{k} <-> L{linha_pivo}")
                print("A após troca:")
                print(A)
                print("b após troca:", b)

        pivo = A[k, k]

        if mostrar_passos:
            print(f"\nEtapa k={k}: pivô escolhido = {pivo:.6f}")

        for i in range(k + 1, n):
            m = A[i, k] / pivo
            A[i, k:] = A[i, k:] - m * A[k, k:]
            b[i] = b[i] - m * b[k]

            if mostrar_passos:
                print(f"  L{i} <- L{i} - ({m:.6f}) L{k}")
                print("  A atual:")
                print(A)
                print("  b atual:", b)

    x = substituicao_regressiva(A, b, tol=tol)
    return x, A, b

# definindo as matrizes do problema
A = np.array([
    [0.5, 6, 2, 1],
    [7, 2, 1, 1],
    [2, 1, 8, 2],
    [1, 2, 1, 9]
])

b = np.array([41.5, 40, 62, 70])

# chamando a função:
x_pivo, U_pivo, c_pivo = gauss_com_pivoteamento_parcial(A, b, mostrar_passos=True)

print("\nSolução com pivoteamento parcial:")
print(x_pivo)

# print("\nResidual:")
# print(residual(A_ruim, x_pivo, b_ruim))
