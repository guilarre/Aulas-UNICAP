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

int inverte_li(Lista L1, Lista L2) {
    if (L1 == NULL || L1->qtd == 0) return 1;

    int topo = -1;
    int pilha[L1->qtd];

    No aux = L1->inicio;
    while (aux != NULL) {
        pilha[++topo] = aux->valor;
        aux = aux->prox;
    }

    for (int i = 0; i < L1->qtd; i++) {
        insere_final(L2, pilha[topo--]);
    }

    return 0;
}

int main() {
    Lista L1 = cria_lista();

    printf("Inserindo elementos na lista...\n");

    insere_inicio(L1, 1);
    insere_inicio(L1, 2);
    insere_inicio(L1, 3);
    remove_inicio(L1);
    insere_final(L1, 4);
    insere_final(L1, 5);
    remove_final(L1);
    insere_final(L1, 6);
    insere_final(L1, 7);
    insere_inicio(L1, 8);

    printa_lista(L1);

    printf("Invertendo lista...\n");
    Lista L2 = cria_lista();
    int erro = inverte_li(L1, L2);
    printa_lista(L2);

    destroi_lista(L1);
    destroi_lista(L2);

    return 0;
}
