// // Versão do professor, usando ponteiros
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #define N 10

// int main() {
//     // Alocando um espaço de memória do tamanho de um float
//     float *v = malloc(N * sizeof(float));
//     float soma = 0;

//     // Loop para inserir valores aleatórios nos espaços seguintes
//     // (essencialmente igual um vetor de floats)
//     for (int i = 0; i < N; i++) {
//         *(v+i) = (float) (rand() % 100)*1.5; //rand() usa uma seed padrão, por isso valores são iguais entre execuções
//         soma += *(v+i);
//         // printf("valor inserido: %.2f\n", *(v+i));
//         // printf("endereco valor inserido: %p\n", (v+i));
//     }
//     float media = soma / N;
//     float soma_erros = 0;

//     for (int i = 0; i < N; i++) {
//         soma_erros += (*(v+i) - media) * (*(v+i) - media);
//     }

//     float dp = soma_erros / (N-1);
//     dp = sqrt(dp);
//     printf("desvio padrao: %.2f\n", dp);

//     free(v); // Desalocar a memória após terminar programa

//     return 0;
// }


// Minha versão: tá dando erro e sempre printando 0

#include <stdio.h>
#include <math.h>

#define N 10
int main() {
    float v[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float soma_m = 0;
    float dp = 0;
    float somatorio = 0;
    for (int i = 0; i < N; i++) {
        soma_m += v[i];
    }
    float m = soma_m / N;

    for (int i = 0; i < N; i++) {
        somatorio += (v[i]-m)*(v[i]-m);
    }

    dp = sqrt((1/(float)(N-1))*somatorio);
    printf("O desvio padrao eh: %.4f", dp);

    return 0;
}