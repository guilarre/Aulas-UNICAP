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

    int removido[N];
    for (int i = 0; i < N; i++) {
        removido[i] = 0;
    }

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (arrayN[i] == arrayM[j]) {
                removido[i] = 1;
            }
        }
    }
 
    for (int i = 0; i < N; i++) {
        if (!removido[i])
            printf("%d ", arrayN[i]);
    }
    printf("\n");

    return 0;
}
