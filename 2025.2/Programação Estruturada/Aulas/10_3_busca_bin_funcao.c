#include <stdio.h>
// Definindo a função
int busca_binaria(int vetor[], int tamanho_vetor, int valor_buscado) {
    int ini = 0;
    int fim = tamanho_vetor-1;
    int pos = -1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (vetor[meio] == valor_buscado) {
            pos = meio;
            return pos;
        } else {
            if (vetor[meio] < valor_buscado) {
                ini = meio + 1;
            } else {
                fim = meio - 1;
            }
        }
    }
    return pos;
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 12, 15, 20};
    int tamanho_vetor = sizeof(vetor)/sizeof(vetor[0]);
    int valor_buscado = 12;
    int resultado_busca;

    // Chamando a função
    resultado_busca = busca_binaria(vetor, tamanho_vetor, valor_buscado);
    
    if (resultado_busca == -1) {
        printf("Nao encontrado.\n");
    } else {
        printf("Valor: %d, encontrado em v[%d].\n", valor_buscado, resultado_busca);
    }

    return 0;
}