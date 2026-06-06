#include "q7.h"

Lista criar_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li == NULL) return NULL;
    li->inicio = NULL;
    li->qtd = 0;
    return li;
}

int inserir_inicio(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    no->prox = li->inicio;
    li->inicio = no;
    li->qtd++;
    return 0;
}

int inserir_fim(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    no->prox = NULL;

    if (li->qtd == 0) {
        li->inicio = no;
        li->qtd++;
        return 0;
    } else if (li->qtd > 0) {
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

int remover_inicio(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    Elem aux = li->inicio;
    li->inicio = aux->prox;
    free(aux);
    li->qtd--;
    return 0;
}

int remover_fim(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    Elem aux = li->inicio;
    if (aux->prox == NULL) {
        free(aux);
        li->inicio = NULL;
        li->qtd--;
        return 0;
    }
    Elem ant;
    while (aux->prox != NULL) {
        ant = aux;
        aux = aux->prox;
    }
    free(aux);
    ant->prox = NULL;
    li->qtd--;
    return 0;
}

int tamanho_lista(Lista li) {
    if (li == NULL || li->qtd == 0) return 0;
    return li->qtd;
}

void destruir_lista(Lista li) {
    if (li == NULL) return;
    Elem aux = li->inicio;
    Elem prox;
    while (aux != NULL) {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
    free(li);
}

void printar_lista(Lista li) {
    if (li == NULL || li->qtd == 0) printf("[ ]");
    Elem aux = li->inicio;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}
