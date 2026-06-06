// TODO:

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento *prox;
} *Elem;

typedef struct fila {
    int qtd;
    Elem inicio;
    Elem final;
} *Fila;

Fila cria_fila() {
    Fila f = malloc(sizeof(struct fila));
    if (f == NULL) return NULL;
    f->qtd = 0;
    f->inicio = NULL;
    f->final = NULL;
    return f;
}

int enqueue(Fila f, int valor) {
    if (f == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    no->prox = NULL;
    if (f->qtd == 0) {
        f->inicio = no;
        f->final = no;
    } else {
        f->final->prox = no;
        f->final = no;
    }
    f->qtd++;
    return 0;
}

int dequeue(Fila f) {
    if (f == NULL || f->qtd == 0) return 1;
    if (f->qtd == 1) { // ou pode fazer f->inicio == f->final
        free(f->inicio);
        f->inicio = NULL;
        f->final = NULL;
    } else {
        Elem aux = f->inicio; //quem vai sair
        f->inicio = f->inicio->prox; //novo início
        free(aux);
    }
    f->qtd--;
    return 0;
}

int is_empty(Fila f) {
    // TODO:
}
