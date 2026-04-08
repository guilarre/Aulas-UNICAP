#include "q7.h"

int main() {
    Lista li = criar_lista();

    printf("Insira valores para a lista (digite qualquer letra caso queira parar):\n");
    int valor_lido = 0;
    while (scanf("%d", &valor_lido) == 1) {
        inserir_fim(li, valor_lido);
    }

    printf("Valores da lista: ");
    printar_lista(li);

    return 0;
}
