#include <stdio.h>
int main() {
    int n;
    while (scanf("%d", &n) && n != 0) { // se receber 0, vai parar
        int baralho[50]; // baralho inicial
        int qtdbaralho = n;
        int descarte[50];

        // populando baralho inicial
        for (int i = 0; i < n; i++) {
            baralho[i] = i+1;
        }

        // OPERAÇÕES
        int topo = 0, base = n; // índice de controle das operações sobre o baralho
        int j = 0; // índice de controle do descarte
        while (qtdbaralho >= 2) {
            // decarta do topo
            descarte[j++] = baralho[topo % n];
            topo++;
            qtdbaralho--;

            // move próximo pro final
            baralho[base % n] = baralho[topo % n];
            base++;
            topo++;
        }

        // output
        printf("Discarded cards: ");
        for (int i = 0; i < j; i++) {
            printf("%d", descarte[i]);
            if (i < j-1) {
                printf(", ");
            }
        }
        printf("\n");
        printf("Remaining card: %d\n", baralho[topo % n]);
    }

    return 0;
}
