#include <stdio.h>
int main() {
    // Criar vetor
    int v[10] = {1, 2, 3, 4, 5, 6, 6, 8, 5, 10};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j) { 
            continue; // No caso de comparar os mesmos índices
            }
            if (v[i] == v[j]) {
                printf("v[%d]: %d\n", i, v[i]);
            }
        }
    }

    return 0;
}