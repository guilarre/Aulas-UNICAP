#include "q6.h"

int main() {
    Lista li = criar_lista();
    inserir_fim(li, 1);
    inserir_fim(li, 0);
    inserir_fim(li, 5);
    inserir_fim(li, -2);
    inserir_fim(li, -5);
    inserir_fim(li, 7);

    printf("tamanho da lista = %d\n", tamanho_lista(li));
    printar_lista(li);

    int total = 0;
    soma_1_2_ult(li, &total);
    printf("soma_1_2_ult = %d\n", total);

    printf("Modificando a pos 0 para 3...\n");
    mod_elem(li, 0, 3);
    printar_lista(li);

    destruir_lista(li);
    return 0;
}
