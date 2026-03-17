#include "fila_int.h"

// Exercício de sala:
// Dada uma fila de inteiros, escreva uma função que remova todos os números negativos da fila, mantendo a ordem relativa dos demais elementos

void remover_negativos(Fila f) {
    Fila aux = cria_fila();
    int valor;
    int n = tamanho(f);
    for (int i = 0; i < n; i++) {
        acessar(f, &valor);
        remover_fila(f);
        if (valor > 0)
            inserir_fila(f, valor);
    }
}

int main() {
    Fila f = cria_fila();

    inserir_fila(f, 10);
    inserir_fila(f, 20);
    inserir_fila(f, 30);
    remover_fila(f);
    inserir_fila(f, 50);
    remover_fila(f);
    inserir_fila(f, 60);
    inserir_fila(f, -2);
    inserir_fila(f, -5);

    int valor; // pra receber o valor consultado

    // if (!acessar(f, &valor))
    //     printf("Começo da fila: %d", valor);
    // else
    //     printf("Erro ao acessar fila");

    remover_negativos(f);

    printf("%d\n", tamanho(f));
    while (tamanho(f)) {
        if (!acessar(f, &valor)) {
            printf("%d\n", valor);
            remover_fila(f);
        }
    }

    destruir_fila(f);
    return 0;
}
