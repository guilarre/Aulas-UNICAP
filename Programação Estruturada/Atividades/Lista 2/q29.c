#include <stdio.h>
#include <stdlib.h>
int main() {
    int zero_count = 0;

    // Alocando 1500 ints para v
    int *v = calloc(1500, sizeof(int));

    // Loop para checar valores inicializados com 0
    for (int i = 0; i < 1500; i++) {
        if (v[i] == 0) {
            zero_count++;
        }
    }

    // Printando qtd de valores 0
    printf("No total, foram inicializados %d valores com 0!\n", zero_count);

    // Atribuindo o valor do índice para cada elemento
    for (int i = 0; i < 1500; i++) {
        v[i] = i;
    }

    // Exibindo 10 primeiros e 10 últimos
    printf("\n10 primeiros elementos:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("\n10 últimos elementos:\n");
    for (int i = 1499; i > 1489; i--) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
