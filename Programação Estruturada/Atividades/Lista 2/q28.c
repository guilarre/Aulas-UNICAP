#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    int *v = NULL;
    int count_pares = 0;
    int count_impares = 0;

    // Recebendo n do usuário
    printf("Digite o número de elementos para um vetor v:\n");
    if (scanf("%d", &n) == 0) {
        printf("ERRO! Digite apenas números inteiros\n");
        return 1;
    }

   // Realocando para o tamanho de n
    v = realloc(v, n * sizeof(int));

    // Pegar do usuário os elementos de v
    printf("Digite os números para o vetor v:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &v[i]) == 0) {
            printf("ERRO! Digite apenas números inteiros\n");
            return 1;
        }

        if (v[i] % 2 == 0) {
            count_pares++;
        } else {
            count_impares++;
        }
    }

    // Imprimindo o vetor lido
    printf("\nVetor lido:\nv = ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    // Imprimindo qtd de pares e ímpares
    printf("No vetor, %d números são pares e %d são ímpares.", count_pares, count_impares);

    // Liberando memória
    free(v);
    return 0;
}
