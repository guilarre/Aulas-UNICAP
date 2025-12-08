#include <stdio.h>
#include <stdlib.h>
int main() {
    // Inicializações
    int n = 10;
    int *v = malloc(n * sizeof(int)); // Inicia com n espaços
    if (v == NULL) {
        printf("ERRO: Falha ao alocar memória!\n");
        return 1;
    }
    int num = -1;
    int k = 0; // Iterador do número de elementos de v

    // Loop para inserir no vetor e alocar dinamicamente
    // sem realloc()
    printf("Digite uma sequência de números qualquer (quando desejar parar digite 0):\n\n");
    while (1) {
        if (scanf("%d", &num) == 0) {
            printf("ERRO: Digite apenas números inteiros!\n");
            free(v);
            return 1;
        }

        if (num == 0) break; // Verifica o 0 para parar

        // Checa qnd vetor tá cheio e aloca mais 10 espaços
        if (k == n) {
            int novo_tamanho = n + 10;
            int *novo_v = malloc(novo_tamanho * sizeof(int));
            if (novo_v == NULL) {
                printf("ERRO: Falha ao alocar memória!\n");
                return 1;
            }

            // Copia do v[i] antigo pro novo
            for (int i = 0; i < n; i++) {
                novo_v[i] = v[i];
            }

            free(v); // Libera v
            v = novo_v; // Ponteiro agora aponta pro novo
            n = novo_tamanho; // Atualiza tamanho
        }

        v[k++] = num; // HACK: doidera movéi
    }

    printf("\nVetor lido:\n");
    for (int i = 0; i < k; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);
    return 0;
}
