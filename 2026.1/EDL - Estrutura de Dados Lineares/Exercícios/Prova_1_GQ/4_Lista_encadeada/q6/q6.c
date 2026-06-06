#include "q6.h"
#include <stdlib.h>

Lista criar_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li == NULL) return NULL;
    li->inicio = NULL;
    li->qtd = 0;
    return li;
}

int tamanho_lista(Lista li) {
    if (li == NULL || li->qtd == 0) return 0;
    return li->qtd;
}

int inserir_inicio(Lista li, int valor) {
    if (li == NULL) return 1;

    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;

    no->valor = valor;
    no->prox = li->inicio; //se vazia, já aponta para NULL
    li->inicio = no;
    li->qtd++;
    return 0;
}

int inserir_fim(Lista li, int valor) {
    if (li == NULL) return 1;

    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->prox = NULL;
    no->valor = valor;

    if (li->qtd == 0) { //se vazia
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
    } else {
        return 1;
    }
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

int mod_elem(Lista li, int pos, int valor_novo) {
    if (li == NULL || pos < 0 || pos >= li->qtd) return 1;

    Elem aux = li->inicio;
    for (int i = 0; i < pos; i++) {
        aux = aux->prox;
    }
    aux->valor = valor_novo;
    return 0;
}

void printar_lista(Lista li) {
    if (li == NULL || li->qtd == 0) printf("[ ]\n");
    Elem aux = li->inicio;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

int soma_1_2_ult(Lista li, int *total) {
    if (li == NULL || li->qtd < 3) return 1;
    int soma = 0;
    soma = li->inicio->valor;
    soma += li->inicio->prox->valor;
    Elem aux = li->inicio;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    soma += aux->valor;
    *total = soma;
    return 0;
}
