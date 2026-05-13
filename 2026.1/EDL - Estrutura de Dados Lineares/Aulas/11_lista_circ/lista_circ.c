#include <stdlib.h>
#include <stdio.h>

typedef struct elemento {
    int valor;
    struct elemento *prox;
} *Elem;

typedef struct lista {
    int qtd;
    Elem final;
} *Lista;

Lista criar_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li == NULL) return NULL;
    li->final = NULL;
    li->qtd = 0;
    return li;
}

int inserir_inicio(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    if (li->final == NULL) { // 0 elem
        no->prox = no;
        li->final = no;
        li->qtd++;
        return 0;
    } // pelo menos 1 elem
    no->prox = li->final->prox;
    li->final->prox = no;
    li->qtd++;
    return 0;
}

int inserir_final(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    if (li->final == NULL) { // 0 elem
        li->final = no;
        no->prox = no;
        li->qtd++;
        return 0;
    }
    no->prox = li->final->prox;
    li->final = no;
    li->qtd++;
    return 0;
}

int remover_inicio(Lista li) {
    if (li == NULL) return 1;
    if (li->final == NULL || li->qtd == 0) return 1;
    Elem aux = li->final->prox; // elem a apagar
    if (aux == li->final) {
        li->final = NULL;
    } else {
        li->final->prox = aux->prox;
    }
    free(aux);
    li->qtd--;
    return 0;
}

int remover_final(Lista li) {
    if (li == NULL || li->final == NULL || li->qtd == 0) return 1;
    Elem no = li->final;
    if (no->prox == no) {
        li->final = NULL;
    } else {
        Elem aux = li->final->prox;
        while (aux->prox != no) {
            aux = aux->prox;
        } // aux = penúltimo
        aux->prox = li->final->prox;
        li->final = aux;
    }
    free(no);
    li->qtd--;
    return 0;
}

// TODO: 
int acessar_inicio(Lista li, int* valor){
}

int acessar_final(Lista li, int* valor){
}

void destruir(Lista li){
}

int tamanho_lista(Lista li){
}
