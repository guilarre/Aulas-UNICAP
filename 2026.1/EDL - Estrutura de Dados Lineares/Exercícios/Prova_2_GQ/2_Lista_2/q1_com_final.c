#include <stdlib.h>
#include <stdio.h>

// Lista unicamente encadeada

// cria_lista
// libera_lista
// lista_vazia
// tamanho_lista
// insere_inicio
// insere_final
// remove_inicio
// remove_final
// imprime_lista
// imprime_lista_reverso
// busca_valor
// consulta_lista_posicao

typedef struct elemento {
    int valor;
    struct elemento *prox;
} *Elem;

// TODO: implementar uma versão sem final p treinar
typedef struct lista {
    int qtd;
    Elem inicio, final; //final simplifica insere_final
} *Lista;

Lista cria_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li == NULL) return NULL;
    li->qtd = 0;
    li->inicio = NULL;
    li->final = NULL;
    return li;
}

int insere_inicio(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    if (li->inicio == NULL) { //nenhum elem
        li->final = no;
    }
    no->prox = li->inicio; //NULL ou elem
    li->inicio = no;
    li->qtd++;
    return 0;
}

int insere_final(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    no->prox = NULL;
    if (li->inicio == NULL) { //nenhum elem
        li->inicio = no;
    }
    li->final->prox = no;
    li->final = no;
    li->qtd++;
    return 0;
}

int remove_inicio(Lista li) {
    if (li == NULL || li->inicio == NULL) return 1;
    if (li->inicio->prox == NULL) { //só 1 elem
        free(li->inicio);
        li->inicio = NULL;
        li->final = NULL;
    } else { // + de 1 elem
        Elem aux = li->inicio;
        li->inicio = li->inicio->prox;
        free(aux);
    }
    li->qtd--;
    return 0;
}

int remove_final(Lista li) {
    if (li == NULL || li->inicio == NULL) return 1;
    if (li->inicio->prox == NULL) { //só 1 elem
        free(li->final);
        li->final = NULL;
        li->inicio = NULL;
    } else { // + de 1 elem
        //n tem como fugir do loop mesmo com li->final
        //pq precisa pegar o penultimo
        Elem aux = li->inicio;
        Elem ant;
        while (aux->prox != NULL) {
            ant = aux;
            aux = aux->prox;
        }
        li->final = ant;
        free(aux);
        ant->prox = NULL;
    }
    li->qtd--;
    return 0;
}

int lista_vazia(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    return 0;
}

int tamanho_lista(Lista li) {
    if (li == NULL || li->qtd == 0) return 0;
    return li->qtd;
}

void imprime_lista(Lista li) {
    
}

void imprime_lista_reverso(Lista li) {

}

Elem busca_valor(Lista li, int valor) {

}

Elem consulta_lista_posicao(Lista li, int pos) {

}

void libera_lista(Lista li) {

}

