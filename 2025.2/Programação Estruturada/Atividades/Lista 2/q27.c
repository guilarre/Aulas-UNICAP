#include <stdio.h>
int main() {
    int n = 5;
    float v[n];
    float soma = 0;
    float media = 0;

    printf("Digite %d valores para o vetor v:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &v[i]);
        soma += v[i];
    }

    printf("\nv[%d] = ", n);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", v[i]);
    }
    printf("\n");

    media = soma/n;
    printf("\nMédia dos valores = %.2f\n", media);

    return 0;
}

// Versão dinâmica
// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int n;
//     float *v = NULL;
//     float soma = 0;
//     float media;
//
//     // Recebendo n do usuário
//     printf("Digite o número de floats para um vetor v:\n");
//     if (scanf("%d", &n) == 0) {
//         printf("ERRO! Digite apenas números (inteiros)\n");
//         return 1;
//     }
//
//    // Realocando para o tamanho de n
//     v = realloc(v, n * sizeof(float));
//
//     // Pegar do usuário os elementos de v
//     printf("Digite os números (float) para o vetor v:\n");
//     for (int i = 0; i < n; i++) {
//         if (scanf("%f", &v[i]) == 0) {
//             printf("ERRO! Digite apenas números (inteiros)\n");
//             return 1;
//         }
//         soma += v[i];
//     }
//
//     // Imprimindo o vetor lido
//     printf("\nVetor lido:\nv = ");
//     for (int i = 0; i < n; i++) {
//         printf("%.2f ", v[i]);
//     }
//     printf("\n");
//
//     // Calculando a média
//     media = soma / n;
//     printf("\nA média dos valores de v é: %.2f", media);
//
//     // Liberando memória
//     free(v);
//     return 0;
// }
