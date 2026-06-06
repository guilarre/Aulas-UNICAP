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

Lista criar_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li == NULL) return NULL;
    li->qtd = 0;
    li->inicio = NULL;
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
    if (li == NULL || li->qtd == 0) return;
    Elem aux = li->inicio;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void soma_2_pos(Lista li, int pos1, int pos2) {
    if (li == NULL || li->qtd == 0) {
        printf("ERRO! Lista vazia\n");
        return;
    }
    if (li->qtd <= pos1 || li->qtd <= pos2) {
        printf("ERRO! Posições dadas devem existir na lista\n");
        return;
    }
    Elem aux = li->inicio;
    int soma = 0;
    int i = 0;
    while (aux != NULL) {
        if (i == pos1) soma += aux->valor;
        if (i == pos2) soma += aux->valor;
        aux = aux->prox;
        i++;
    }
    printf("Soma = %d\n", soma);
}

int main() {
    Lista li = criar_lista();
    inserir_fim(li, 1);
    inserir_fim(li, 2);
    inserir_fim(li, 3);
    inserir_fim(li, 4);

    printar_lista(li);
    soma_2_pos(li, 3, 0);

    destruir_lista(li);
    return 0;
}
