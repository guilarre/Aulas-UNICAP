#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento *prox;
} *Elem;

typedef struct lista {
    int qtd;
    Elem inicio;
} *Lista;

Lista cria_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li == NULL) return NULL;
    li->qtd = 0;
    li->inicio = NULL;
    return li;
}

int insere_inicio(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no != NULL && li->qtd == 0) { //se lista vazia
        no->valor = valor;
        no->prox = NULL;
        li->inicio = no;
        li->qtd++;
        return 0;
    } else if (no != NULL && li->qtd > 0) {
        no->valor = valor;
        no->prox = li->inicio;
        li->inicio = no;
        li->qtd++;
        return 0;
    } else {
        return 1;
    }
}

int insere_fim(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    no->valor = valor;
    no->prox = NULL;
    if (no != NULL && li->qtd == 0) { //se vazia
        li->inicio = no;
        li->qtd++;
        return 0;
    } else if (no != NULL && li->qtd > 0) {
        //percorrer até último
        Elem aux = li->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
        li->qtd++;
        return 0;
    }
    return 1;
}

int remove_inicio(Lista li) {
    // TODO:
}

int main() {
    return 0;
}
