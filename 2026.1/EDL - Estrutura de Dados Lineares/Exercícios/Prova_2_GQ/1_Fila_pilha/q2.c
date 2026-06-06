#include <stdlib.h>
#include <stdio.h>

// Pilha dinâmica = LIFO

typedef struct elemento {
    int valor;
    struct elemento *prox; //proximo abaixo do topo
} *Elem;

typedef struct pilha {
    int qtd;
    Elem topo;
} *Pilha;

Pilha cria_pilha() {
    Pilha p = malloc(sizeof(struct pilha));
    if (p == NULL) return NULL;
    p->qtd = 0;
    p->topo = NULL;
    return p;
}

int empilha(Pilha p, int valor) {
    if (p == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    no->prox = p->topo; //ou NULL ou algum elem
    p->topo = no;
    p->qtd++;
    return 0;
}

int desempilha(Pilha p) {
    if (p == NULL || p->qtd == 0) return 1;
    if (p->topo->prox == NULL) { //só tem 1 elem
        free(p->topo);
        p->topo = NULL;
    } else { //tem mais de 1 elem
        Elem aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
    p->qtd--;
    return 0;
}

int topo(Pilha p, int *valor) {
    if (p == NULL || p->topo == NULL) return 1;
    *valor = p->topo->valor;
    return 0;
}

int tamanho_pilha(Pilha p) {
    if (p == NULL || p->topo == NULL) return 0;
    return p->qtd;
}

int pilha_vazia(Pilha p) {
    if (p == NULL || p->topo == NULL) return 1;
    return 0;
}

void imprime_pilha(Pilha p) {
    if (p != NULL) {
        Elem aux = p->topo;
        printf("Elementos da pilha:\n[ ");
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("]\n");
    }
}

void libera_pilha(Pilha p) {
    if (p != NULL) {
        Elem aux = p->topo;
        Elem prox;
        while (aux != NULL) {
            prox = aux->prox;
            free(aux);
            aux = prox;
        }
        free(p);
    }
}

int main() {
    Pilha p = cria_pilha();

    printf("Pilha vazia? R: %d\n", pilha_vazia(p));

    empilha(p, 1);
    empilha(p, 2);
    empilha(p, 3);
    desempilha(p);
    empilha(p, 4);

    imprime_pilha(p);

    printf("Pilha vazia? R: %d\n", pilha_vazia(p));

    printf("Tamanho da pilha = %d\n", tamanho_pilha(p));

    int valor;
    topo(p, &valor);
    printf("Topo da pilha = %d\n", valor);

    libera_pilha(p);

    return 0;
}
