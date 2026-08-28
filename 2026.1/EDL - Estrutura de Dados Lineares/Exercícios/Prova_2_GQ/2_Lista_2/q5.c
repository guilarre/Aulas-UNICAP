#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int valor;
    struct no *prox;
} *No;

typedef struct lista {
    int qtd;
    No inicio;
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
    No no = malloc(sizeof(struct no));
    if (no == NULL) return 1;
    no->valor = valor;
    if (li->qtd == 0) {
        no->prox = NULL;
    } else {
        no->prox = li->inicio;
    }
    li->inicio = no;
    li->qtd++;
    return 0;
}

int insere_final(Lista li, int valor) {
    if (li == NULL) return 1;
    No no = malloc(sizeof(struct no));
    if (no == NULL) return 1;
    no->valor = valor;
    no->prox = NULL;
    if (li->qtd == 0) {
        li->inicio = no;
    } else {
        No aux = li->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    li->qtd++;
    return 0;
}

int remove_inicio(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    if (li->qtd == 1) {
        free(li->inicio);
        li->inicio = NULL;
    } else {
        No aux = li->inicio;
        li->inicio = li->inicio->prox;
        free(aux);
    }
    li->qtd--;
    return 0;
}

int remove_final(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    if (li->qtd == 1) {
        free(li->inicio);
        li->inicio = NULL;
    } else {
        No aux = li->inicio;
        No ant;
        while (aux->prox != NULL) {
            ant = aux;
            aux = aux->prox;
        }
        free(aux);
        ant->prox = NULL;
    }
    li->qtd--;
    return 0;
}

void destroi_lista(Lista li) {
    if (li != NULL) {
        if (li->qtd != 0) {
            No aux = li->inicio;
            No prox;
            while (aux != NULL) {
                prox = aux->prox;
                free(aux);
                aux = prox;
            }
        }
        free (li);
    }
}

void printa_lista(Lista li) {
    if (li != NULL && li->qtd != 0) {
        No aux = li->inicio;
        printf("Elementos = [ ");
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("]\n");
    }
}

int remover_n_primeiros(Lista li, int n) {
    if (li == NULL || li->qtd == 0 || n > li->qtd) return 1;
    for (int i = 0; i < n; i++) {
        remove_inicio(li);
    }
    return 0;
}

int main() {
    Lista li = cria_lista();

    printf("Inserindo elementos na lista...\n");

    insere_inicio(li, 1);
    insere_inicio(li, 2);
    insere_inicio(li, 3);
    remove_inicio(li);
    insere_final(li, 4);
    insere_final(li, 5);
    remove_final(li);
    insere_final(li, 6);
    insere_final(li, 7);

    printa_lista(li);

    remover_n_primeiros(li, 3);
    printa_lista(li);

    destroi_lista(li);

    return 0;
}
