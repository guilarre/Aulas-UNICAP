#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    int arrayN[N]; // array inicial
    for (int i = 0; i < N; i++) {
        scanf("%d", &arrayN[i]);
    }

    int M;
    scanf("%d", &M);
    int arrayM[M]; // array com os ids a serem retirados
    for (int i = 0; i < M; i++) {
        scanf("%d", &arrayM[i]);
    }

    // vai criar um array pra cada id possível
    int removido[100001] = {0};
    for (int i = 0; i < M; i++) {
        removido[arrayM[i]] = 1;
    }

    int primeiro = 1;
    for (int i = 0; i < N; i++) {
        if (!removido[arrayN[i]]) {
            if (!primeiro) printf(" ");
            printf("%d", arrayN[i]);
            primeiro = 0;
        }
    }
    printf("\n");

    return 0;
}
