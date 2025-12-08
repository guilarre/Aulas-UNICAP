#include <stdio.h>
#define N 10

int maior_valor(int v[]) {
    int maior = v[0];
    int i;
    for (i = 1; i < N; i++) {
        if (maior < v[i]) {
            maior = v[i];
        }
    }
    return maior;
}

int main() {
    int v[N], i, k;

    printf("Digite 10 elementos inteiros para o vetor v[%d]:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    printf("\nDigite o número de elementos por linha (k):\n");
    scanf("%d", &k);
 
    printf("\nVetor v com %d elementos por linha:\n", k);
    for (i = 0; i < N; i++) {
        printf("%d ", v[i]);
        if ((i+1) % k == 0) {
            printf("\n");
        }
    }
    printf("\n");

    printf("\nO maior elemento do vetor é: %d\n", maior_valor(v));

    return 0;
}
