#include <stdio.h>
#include <stdlib.h>
int main() {
    int *v = NULL;
    int i = 0;
    int num;

    // Recebendo elementos do usuário
    printf("Digite valores para o vetor v (quando desejar parar digite um número negativo):\n");
    while (1) {
        if (scanf("%d", &num) != 0 && num > 0) {
            v = realloc(v, (i+1)*sizeof(int)); // Realocando
            if (v == NULL) {
                printf("ERRO: Falha em realocar a memória!\n");
                return 1;
            }
            v[i] = num;

            i++;
        } else {
            break;
        }
    }

    // Imprimindo o vetor lido
    printf("\nVetor lido:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");

    free(v);
    return 0;
}
