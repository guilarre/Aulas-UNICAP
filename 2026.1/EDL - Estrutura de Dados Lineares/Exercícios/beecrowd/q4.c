#include <stdio.h>
int main() {
    int n;
    while (scanf("%d", &n) && n != 0) { // se receber 0, vai parar
        int fila[50]; // fila circular
        int frente = 0, tras = n; // indices pra uma fila circular

        // populando baralho inicial
        for (int i = 0; i < n; i++) {
            fila[i] = i+1;
        }

        printf("Discarded cards: ");

        while ((tras - frente) > 1) {
            printf("%d", fila[frente % 50]); // % faz com que volte pra posição inicial após estourar o limite
            if ((tras - frente) > 2) printf(", ");
        }
    }
    return 0;
}
