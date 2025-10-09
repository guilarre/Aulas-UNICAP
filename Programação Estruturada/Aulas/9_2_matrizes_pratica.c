#include <stdio.h>
#define N 2

void somar_matrizes(int A[N][N], int B[N][N], int S[N][N]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            S[i][j] = A[i][j] + B[i][j];
        }
    }
}

void transpor_matriz(int A[N][N], int T[N][N]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            T[i][j] = A[j][i];
        }
    }
}

void multiplicar_matrizes(int A[N][N], int B[N][N], int M[N][N]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                M[i][j] += A[i][k]*B[k][j];
            }
        }        
    }
}

int main() {
    // QUESTÃO 1: Soma das matrizes A e B
    int A[N][N] = {
        {1, 2},
        {5, 6}
    };
    int B[N][N] = {
        {3, 4},
        {7, 8}
    };

    // Somando
    int S[N][N];
    somar_matrizes(A, B, S);

    // Printando a matriz soma
    printf("Soma: \n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("%d ", S[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    // QUESTÃO 2: Transposta de A = {{1, 2}, {3, 4}}
    int C[2][2] = {{1, 2}, {3, 4}};
    
    // Transpondo
    int T[N][N];
    transpor_matriz(C, T);

    // Printando a matriz
    printf("Transposta: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    // QUESTÃO 3: Multiplicação de matrizes
    // Zerando M pra evitar lixo de memória na soma
    int M[N][N] = {{0, 0}, {0, 0}};

    // Multiplicando
    multiplicar_matrizes(A, B, M);

    // Printando a matriz
    printf("Multiplicação: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}