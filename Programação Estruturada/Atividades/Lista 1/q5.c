#include <stdio.h>
int main() {
    int soma = 0;
    int m[3][3];

    // Prompt
    printf("Insira os valores para uma matriz 3x3:\n");

    // Lendo a matriz do input
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int elem;
            printf("M(%d, %d):\n", i+1, j+1);
            scanf("%d", &elem);
            m[i][j] = elem;
        }
    }

    // Printando a matriz em tela
    printf("\nMatriz inserida:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i == 1 && j == 0) || (i == 2 && j == 0)) {
                printf("\n");
            }
            printf("%d\t", m[i][j]);
        }
    }

    // Soma dos elementos da diagonal principal
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                soma += m[i][j];
            }
        }
    }

    // Resultado
    printf("\nSoma da diagonal principal = %d\n", soma);
    return 0;
}