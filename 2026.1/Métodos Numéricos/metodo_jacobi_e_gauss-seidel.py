import numpy as np
import pandas as pd
from itertools import permutations

# Definindo as matrizes do sistema:
A_inicial = np.array([
    [10, 1, 1],
    [1, 10, 1],
    [1, 1, 10]
], dtype=float)

b_inicial = np.array([12, 12, 12], dtype=float)

# Número máximo de iterações desejado
MAX_ITER = 50
# Tolerância desejada
TOLERANCIA = 1e-4

def verifica_dominancia_diagonal(A):
    A = np.array(A, dtype=float)
    resultados = []
    for i in range(A.shape[0]):
        diagonal = abs(A[i, i])
        soma_fora_diagonal = np.sum(np.abs(A[i, :])) - diagonal
        resultados.append({
            "Linha": i + 1,
            "|a_ii| (Diagonal)": round(diagonal, 4),
            "Soma dos outros": round(soma_fora_diagonal, 4),
            "Dominante?": diagonal > soma_fora_diagonal
        })
    return pd.DataFrame(resultados)


def encontrar_permutacao_dominante(A, b):
    n = A.shape[0]
    for perm in permutations(range(n)):
        A_perm = A[list(perm), :]
        b_perm = b[list(perm)]
        resultado = verifica_dominancia_diagonal(A_perm)

        if bool(resultado["Dominante?"].all()):
            return list(perm), A_perm, b_perm, resultado
    return None, A, b, None


def jacobi(A, b, tol, max_iter):
    n = len(b)
    x_old = np.zeros(n, dtype=float)
    history = [x_old.copy()]

    for k in range(max_iter):
        x_new = np.zeros(n, dtype=float)
        for i in range(n):
            soma = sum(A[i, j] * x_old[j] for j in range(n) if j != i)
            x_new[i] = (b[i] - soma) / A[i, i]

        history.append(x_new.copy())
        error = np.max(np.abs(x_new - x_old))
        if error < tol:
            break
        x_old = x_new

    return np.array(history)


def gauss_seidel(A, b, tol, max_iter):
    n = len(b)
    x = np.zeros(n, dtype=float)
    history = [x.copy()]

    for k in range(max_iter):
        x_old = x.copy()
        for i in range(n):
            soma = sum(A[i, j] * x[j] for j in range(n) if j != i)
            x[i] = (b[i] - soma) / A[i, i]

        history.append(x.copy())
        error = np.max(np.abs(x - x_old))
        if error < tol:
            break

    return np.array(history)


def gera_tabela_iteracoes(history, nome_metodo):
    df = pd.DataFrame(history, columns=[f"x{i+1}" for i in range(history.shape[1])])
    df.insert(0, "k", range(len(history)))
    df["Erro Máximo"] = [np.nan] + [
        np.max(np.abs(history[i] - history[i-1])) for i in range(1, len(history))
    ]
    df["Método"] = nome_metodo
    return df


print("="*60)
print("        PASSO 1: ANÁLISE DE DOMINÂNCIA DIAGONAL")
print("="*60)

df_checagem = verifica_dominancia_diagonal(A_inicial)
print("\nChecagem inicial da matriz:")
print(df_checagem.to_string(index=False))

# Se a matriz não for estritamente dominante, busca permutação
if not bool(df_checagem["Dominante?"].all()):
    print("\n[!] A matriz original não é diagonal dominante. Buscando permutação de linhas...")
    perm, A, b, df_resultado_perm = encontrar_permutacao_dominante(A_inicial, b_inicial)

    if perm is not None and df_resultado_perm is not None:
        print(f"✔️ Permutação encontrada! Nova ordem das linhas originais: {[p + 1 for p in perm]}")
        print("\nNova checagem após reordenamento:")
        print(df_resultado_perm.to_string(index=False))
    else:
        print("❌ Não foi encontrada nenhuma permutação que garanta dominância estrita.")
        print("O script continuará com a matriz original (risco de não convergência).")
        A, b = A_inicial, b_inicial
else:
    print("\n✔️ A matriz original já é diagonal dominante! Nenhuma alteração necessária.")
    A, b = A_inicial, b_inicial

print("\nMatriz A utilizada:")
print(A)
print("Vetor b utilizado:", b)


print("\n" + "="*60)
print(f"        PASSO 2: EXECUÇÃO DOS MÉTODOS (MAX_ITER = {MAX_ITER})")
print("="*60)

# Executa Jacobi
hist_jacobi = jacobi(A, b, tol=TOLERANCIA, max_iter=MAX_ITER)
df_jacobi = gera_tabela_iteracoes(hist_jacobi, "Jacobi")
print("\n🔹 TABELA DE ITERAÇÕES - MÉTODO DE JACOBI:")
print(df_jacobi.round(6).to_string(index=False))

# Executa Gauss-Seidel
hist_gs = gauss_seidel(A, b, tol=TOLERANCIA, max_iter=MAX_ITER)
df_gs = gera_tabela_iteracoes(hist_gs, "Gauss-Seidel")
print("\n🔹 TABELA DE ITERAÇÕES - MÉTODO DE GAUSS-SEIDEL:")
print(df_gs.round(6).to_string(index=False))
