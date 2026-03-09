// Pilha = LIFO (Last In, First Out)

// Funções:
// cria_pilha
// push
// peek
// pop
// tamanho_pilha
// destruir_pilha

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct pilha {
    int dados[MAX];
    int topo;
} *Pilha;

Pilha criar_pilha() {
    Pilha p = malloc(sizeof(struct pilha));
    if (p != NULL) {
        p->topo = 0;
    }
    return p;
}

int push(Pilha p, int dado) {
    if (p == NULL)
        return 1;
    if (p->topo < MAX) {
        p->dados[p->topo] = dado;
        p->topo++;
        return 0;
    }
    return 1;
}

int peek(Pilha p, int* dado) {
    if (p == NULL)
        return 1;
    if (p->topo != 0) {
        *dado = p->dados[p->topo - 1];
        return 0;
    }
    return 1;
}

int pop(Pilha p) {
    if (p == NULL)
        return 1;
    if (p->topo != 0) {
        p->topo--;
        return 0;
    }
    return 1;
}

int tamanho_pilha(Pilha p) {
    if (p == NULL)
        return 0;
    return p->topo;
}

void destruir_pilha(Pilha p) {
    if (p != NULL)
        free(p);
}

int main() {
    Pilha p = criar_pilha();
    int dado;

    for (int i = 0; i < MAX; i++) {
        printf("Insira o dado que deseja colocar na pilha: ");
        scanf("%d", &dado);

        if (push(p, dado)) {
            printf("Erro, valor não inserido\n");
        } else {
            printf("Valor %d inserido\n", dado);
        }
        printf("Quantidade de elementos: %d\n", tamanho_pilha(p));
    }

    if (peek(p, &dado)) {
        printf("Erro ao acessar pilha\n");
    } else {
        printf("Tamanho da pilha = %d, último elemento = %d\n", tamanho_pilha(p), dado);
    }

    while (tamanho_pilha(p) != 0) {
        if (peek(p, &dado)) {
            printf("Erro ao acessar pilha\n");
        }
        else {
            printf("Posição = %d, Valor = %d\n", tamanho_pilha(p), dado);
        }
        pop(p);
    }

    destruir_pilha(p);
    return 0;
}
