#include <stdio.h>
#include "quadrado.h"

int main() {
    float lado;
 
    Quadrado lista[TAM];
    for (int i = 0; i < TAM; i++) {
        float lado;
        printf("Insira o lado do quadrado: ");
        scanf("%f", &lado);

        lista[i] = cria_quadrado(lado);
    }

    for (int i = 0; i < TAM; i++) {
        destruir_quadrado(lista[i]);
    }

    return 0;
}
