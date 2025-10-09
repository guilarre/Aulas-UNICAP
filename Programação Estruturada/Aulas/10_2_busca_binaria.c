#include <stdio.h>
int main() {
    int v[] = {1, 3, 5, 7, 9, 12, 15, 20}; // TEM que estar ordenado pra funcionar
    int n = sizeof(v)/sizeof(v[0]);
    int x = 12; // target
    
    int ini = 0;
    int fim = n-1;
    int pos = -1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2; // Arredonda pra baixo (7/2 = 3)
        if (v[meio] == x) {
            pos = meio;
            break;
        } else {
            if (v[meio] < x) {
                ini = meio + 1;
            } else {
                fim = meio - 1;
            }
        }
    }

    if (pos == -1) {
        printf("Nao encontrado.\n"); // Nº de iterações pra valor inexistente = metade do tamanho do vetor
    } else {
        printf("Valor: %d, encontrado em v[%d].\n", x, pos); // Encontra em 2 iterações
    }

    return 0;
}