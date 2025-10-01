#include <stdio.h>

int main() {
    float m[2][2]; // Matriz 2x2

    // Loop aninhado pra iterar M(i, j)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%f", &m[i][j]);
        }
    }

    // Printando através de loop
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("m[%d][%d]: %.2f\n", i, j, m[i][j]);
        }
    }

    // Somando todos os elementos
    float soma = 0; // Definir como 0 pra evitar lixo de memória
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            soma += m[i][j];
        }
    }

    // Printando valor da soma
    printf("Soma: %.2f\n", soma);

    return 0;
}