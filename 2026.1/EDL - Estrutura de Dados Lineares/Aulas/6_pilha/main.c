#include "pilha_char_exercicio.h"

int main() {
    Pilha p = criar_pilha();
    char dado;

    for (int i = 0; i < MAX; i++) {
        printf("Insira o dado que deseja colocar na pilha: ");
        scanf("%c", &dado);

        if (push(p, dado)) {
            printf("Erro, valor não inserido\n");
        } else {
            printf("Valor %c inserido\n", dado);
        }
        printf("Quantidade de elementos: %d\n", tamanho_pilha(p));
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            // Discard characters until newline or EOF
        }
    }

    if (peek(p, &dado)) {
        printf("Erro ao acessar pilha\n");
    } else {
        printf("Tamanho da pilha = %d, último elemento = %c\n", tamanho_pilha(p), dado);
    }

    Pilha p_copy = copiar_pilha(p);

    // Imprimindo o original
    printf("Original:\n");
    while (tamanho_pilha(p) != 0) {
        if (peek(p, &dado)) {
            printf("Erro ao acessar pilha\n");
        }
        else {
            printf("Posição = %d, Valor = %c\n", tamanho_pilha(p), dado);
        }
        pop(p);
    }

    // Imprimindo a cópia
    printf("Cópia:\n");
    while (tamanho_pilha(p_copy) != 0) {
        if (peek(p_copy, &dado)) {
            printf("Erro ao acessar pilha\n");
        }
        else {
            printf("Posição = %d, Valor = %c\n", tamanho_pilha(p_copy), dado);
        }
        pop(p_copy);
    }

    destruir_pilha(p);
    destruir_pilha(p_copy);
    return 0;
}
