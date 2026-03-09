// Pilha = LIFO (Last In, First Out)

// Funções:
// cria_pilha
// push
// peek
// pop
// tamanho_pilha
// destruir_pilha

// Exercício:
// pilha que armazena caracteres
// copiar_pilha() -> receve uma pilha e retorna uma cópia (usando malloc)

#include "pilha_char_exercicio.h"

struct pilha {
    char dados[MAX];
    int topo;
};

Pilha criar_pilha() {
    Pilha p = malloc(sizeof(struct pilha));
    if (p != NULL) {
        p->topo = 0;
    }
    return p;
}

int push(Pilha p, char dado) {
    if (p == NULL)
        return 1;
    if (p->topo < MAX) {
        p->dados[p->topo] = dado;
        p->topo++;
        return 0;
    }
    return 1;
}

int peek(Pilha p, char* dado) {
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

Pilha copiar_pilha(Pilha p) {
    Pilha p_copy = criar_pilha();
    for (int i = 0; i < tamanho_pilha(p); i++) {
        p_copy->dados[i] = p->dados[i];
        p_copy->topo++;
    }
    return p_copy;
}
