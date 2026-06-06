#include <stdio.h>

int main() {
    int N;

    // Inicia leitura (enquanto não for 0)
    while (scanf("%d", &N) && N != 0) {
        while (1) {
            int permutacao[N]; // Permutação final desejada

            scanf("%d", &permutacao[0]);
            // Checando se há um 0 (parar verificação desse caso)
            if (permutacao[0] == 0) {
                printf("\n");
                break;
            }

            // Ler resto
            for (int i = 1; i < N; i++) {
                scanf("%d", &permutacao[i]);
            }

            int pilha[N];
            int topo = -1; // topo da pilha (último elem)
            int i = 0;
            int atual = 1; // vagão atual vindo de A

            while (i < N) {
                if (topo != -1 && pilha[topo] == permutacao[i]) {
                    topo--; // pop
                    i++;
                } else if (atual <= N)
                    pilha[++topo] = atual++; // push
                else break;
            }

            if (i == N)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
