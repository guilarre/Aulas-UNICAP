#include <stdio.h>

int main() {
    int N;

    // Se 0 vai fechar programa
    while (scanf("%d", &N) && N != 0) {
        while (1) {
            int permutacao[N];

            scanf("%d", &permutacao[0]);
            // Checando se há um 0 (parar iteração)
            if (permutacao[0] == 0)
                break;

            // Ler resto
            for (int i = 1; i < N; i++) {
                scanf("%d", &permutacao[i]);
            }
 
            int topo = 0;
        }
    }

    return 0;
}
