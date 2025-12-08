#include <stdio.h>
#include <stdlib.h>
int soma_arrays(int *v1, int *v2, int **v3, int size1, int size2) {
    // Checa se são iguais
    if (size1 != size2) {
        return 0;
    }

    // Se forem iguais, v3 tem o mesmo tamanho
    *v3 = realloc(*v3, size1*sizeof(int));

    // Se realloc tiver sucesso vai somar os elementos em v3
    if (*v3 == NULL) {
        printf("ERRO de alocação de memória!");
        return 0;
    }
    for (int i = 0; i < size1; i++) {
        *(*v3 + i) = *(v1 + i) + *(v2 + i);
    }

    return 1;
}

int main() {
    // TODO: praticar pegar do teclado dinamicamente
    int *v1 = NULL;
    int *v2 = NULL;
    int *v3 = NULL;

    // Vetor 1
    int novo_elemento = -1;
    int i = 0;

    while (1) {
        // Input
        printf("Digite um número para o vetor 1 (digite 0 para parar):\n");
        scanf("%d", &novo_elemento);
        // Se for 0, sair do loop
        if (novo_elemento == 0) {
            break;
        }
        // Realocar memória de v1 e adicionar elemento
        v1 = realloc(v1, (i+1)*sizeof(int));
        if (v1 != NULL) {
            v1[i] = novo_elemento;
        } else {
            printf("ERRO de alocação de memória!");
            return 1;
        }

        i++;
    }

    int size1 = i;
    printf("\nv1[%d] = ", size1);
    for (int i = 0; i < size1; i++) {
        printf("%d ", v1[i]);
    }
    printf("\n");

    // Vetor 2
    novo_elemento = -1;
    i = 0;

    while (1) {
        // Input
        printf("\nDigite um número para o vetor 2 (digite 0 para parar):\n");
        scanf("%d", &novo_elemento);
        // Se for 0, sair do loop
        if (novo_elemento == 0) {
            break;
        }
        // Realocar memória de v1 e adicionar elemento
        v2 = realloc(v2, (i+1)*sizeof(int));
        if (v2 != NULL) {
            v2[i] = novo_elemento;
        } else {
            printf("ERRO de alocação de memória!");
            return 1;
        }

        i++;
    }

    int size2 = i;
    printf("\nv2[%d] = ", size2);
    for (int i = 0; i < size2; i++) {
        printf("%d ", v2[i]);
    }
    printf("\n");

    // Somar arrays
    int result = soma_arrays(v1, v2, &v3, size1, size2);
    if (result == 0) {
        printf("ERRO! Tamanho dos arrays deve ser igual.\n");
        return 1;
    }

    // Printar o resultado
    printf("\nResultado da soma:\nv3[%d] = ", size2);
    for (int i = 0; i < size2; i++) {
        printf("%d ", v3[i]);
    }
    printf("\n");

    // Finalizando programa
    free(v1);
    free(v2);
    free(v3);
    return 0;
}
