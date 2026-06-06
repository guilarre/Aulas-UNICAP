#include <stdlib.h>
#include <stdio.h>

// Lista duplamente encadeada

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
    struct elemento *ant;
} *Elem;

typedef struct lista {
    int qtd;
    Elem inicio, final;
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
    no->ant = NULL;
    no->prox = li->inicio;
    if (li->qtd == 0) {
        li->final = no;
    } else {
        li->inicio->ant = no;
    }
    li->inicio = no;
    li->qtd++;
    return 0;
}

int insere_final(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    no->ant = li->final;
    no->prox = NULL;
    if (li->qtd == 0) {
        li->inicio = no;
    } else {
        li->final->prox = no;
    }
    li->final = no;
    li->qtd++;
    return 0;
}

int remove_inicio(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    if (li->qtd == 1) {
        free(li->inicio);
        li->inicio = NULL;
        li->final = NULL;
    } else {
        Elem aux = li->inicio->prox;
        aux->ant = NULL;
        free(li->inicio);
        li->inicio = aux;
    }
    li->qtd--;
    return 0;
}

int remove_final(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    Elem aux = li->final->ant;
    if (li->qtd == 1) {
        free(li->final);
        li->final = NULL;
        li->inicio = NULL;
    } else {
        free(li->final);
        aux->prox = NULL;
        li->final = aux;
    }
    li->qtd--;
    return 1;
}

void imprime_lista(Lista li) {
    if (li != NULL && li->qtd != 0) {
        Elem aux = li->inicio;
        printf("Elementos = [ ");
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("]\n");
    }
}

void imprime_lista_reverso(Lista li) {
    if (li != NULL && li->qtd != 0) {
        Elem aux = li->final;
        printf("Elementos invertidos = [ ");
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->ant;
        }
        printf("]\n");
    }
}

int tamanho_lista(Lista li) {
    if (li == NULL || li->qtd == 0) return 0;
    return li->qtd;
}

int lista_vazia(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    return 0;
}

Elem busca_valor(Lista li, int valor) {
    if (li == NULL || li->qtd == 0) return NULL;
    Elem aux = li->inicio;
    while (aux != NULL) {
        if (aux->valor == valor) return aux;
        aux = aux->prox;
    }
    printf("Não há elemento de valor '%d' na lista! :(\n", valor);
    return NULL;
}

Elem consulta_lista_posicao(Lista li, int pos) {
    if (li == NULL || li->qtd == 0) return NULL;
    Elem aux = li->inicio;
    int i = 0;
    while (aux != NULL) {
        if (i == pos) return aux;
        i++;
        aux = aux->prox;
    }
    printf("Não existe elemento na posição '%d'! :(\n", pos);
    return NULL;
}

void libera_lista(Lista li) {
    if (li != NULL && li->qtd != 0) {
        Elem aux = li->inicio;
        Elem prox;
        while (aux != NULL) {
            prox = aux->prox;
            free(aux);
            aux = prox;
        }
        free(li);
    }
}

int main() {
    Lista li = cria_lista();

    printf("Lista vazia? R: %d\n", lista_vazia(li));

    insere_final(li, 1);
    insere_final(li, 2);
    insere_final(li, 3);
    remove_inicio(li);
    insere_inicio(li, 4);
    insere_inicio(li, 5);
    insere_inicio(li, 6);
    remove_final(li);

    printf("Lista vazia? R: %d\n", lista_vazia(li));

    imprime_lista(li);
    imprime_lista_reverso(li);

    int valor = 1;
    if (busca_valor(li, valor) != NULL) {
        printf("Valor '%d' encontrado!\n", valor);
    }
    valor = 5;
    if (busca_valor(li, valor) != NULL) {
        printf("Valor '%d' encontrado!\n", valor);
    }

    int pos = 0;
    Elem elem = consulta_lista_posicao(li, pos);
    if (elem != NULL) {
        printf("Valor encontrado na posição '%d': %d\n", pos, elem->valor);
    }
    pos = 9;
    elem = consulta_lista_posicao(li, pos);
    if (elem != NULL) {
        printf("Valor encontrado na posição '%d': %d\n", pos, elem->valor);
    }

    libera_lista(li);

    return 0;
}

