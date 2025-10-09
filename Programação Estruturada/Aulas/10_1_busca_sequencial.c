#include <stdio.h>
int main() {
    // Vetor a ser percorrido
    int v[7] = {1, 3, 7, 12, 18, 25, 33};

    // Valor pesquisado
    int x = 12;

    // Busca sequencial
    for (int i = 0; i < 7; i++) {
        if (v[i] == x) {
            printf("Achou o número: %d, na posição: %d.\n", v[i], i);
            return 0;
        }
    }
    printf("Não achou\n");
    return 1;
}