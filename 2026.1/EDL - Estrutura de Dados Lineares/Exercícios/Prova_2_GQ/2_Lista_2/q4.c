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

Lista lista_cat(Lista l1, Lista l2) {
    if (l1 == NULL || l2 == NULL) return NULL;
    Lista l3 = cria_lista();
    if (l3 == NULL) return NULL;
    l3->qtd = 0;
    l3->inicio = 0;
    No aux = l1->inicio;
    while (aux != NULL) {
        insere_final(l3, aux->valor);
        aux = aux->prox;
    }
    aux = l2->inicio;
    while (aux != NULL) {
        insere_final(l3, aux->valor);
        aux = aux->prox;
    }
    return l3;
}

int main() {
    Lista l1 = cria_lista();

    printf("Inserindo elementos na lista 1...\n");

    insere_inicio(l1, 1);
    insere_inicio(l1, 2);
    insere_inicio(l1, 3);
    remove_inicio(l1);
    insere_final(l1, 4);
    insere_final(l1, 5);
    remove_final(l1);
    insere_final(l1, 6);
    insere_final(l1, 7);

    printa_lista(l1);

    Lista l2 = cria_lista();

    printf("Inserindo elementos...\n");

    insere_inicio(l2, 6);
    insere_inicio(l2, 6);
    insere_inicio(l2, 6);
    remove_inicio(l2);
    insere_final(l2, 6);
    insere_final(l2, 6);
    remove_final(l2);
    insere_final(l2, 6);
    insere_final(l2, 6);

    printa_lista(l2);

    printf("Concatenando listas...\n");
    Lista l3 = lista_cat(l2, l1);

    printa_lista(l3);

    destroi_lista(l1);
    destroi_lista(l2);
    destroi_lista(l3);

    return 0;
}
