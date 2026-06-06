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
    if (no == NULL) return 1;
    no->valor = valor;
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
    } else {
        Elem aux = li->inicio;
            while (aux->prox != NULL) { //para no ultimo
                aux = aux->prox;
            }
        aux->prox = no;
    }
    li->qtd++;
    return 0;
}

int remove_inicio(Lista li) {
    if (li == NULL || li->inicio == NULL) return 1;
    if (li->inicio->prox == NULL) { //só 1 elem
        free(li->inicio);
        li->inicio = NULL;
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
        free(li->inicio);
        li->inicio = NULL;
    } else { // + de 1 elem
        //pq precisa pegar o penultimo
        Elem aux = li->inicio;
        Elem ant;
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

int lista_vazia(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    return 0;
}

int tamanho_lista(Lista li) {
    if (li == NULL || li->qtd == 0) return 0;
    return li->qtd;
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
        int topo = 0;
        int *pilha = malloc(sizeof(int) * li->qtd);
        Elem aux = li->inicio;
        while (aux != NULL) {
            pilha[topo++] = aux->valor;
            aux = aux->prox;
        }
        printf("Elementos reverso = [ ");
        while (topo > 0) {
            printf("%d ", pilha[topo - 1]);
            topo--;
        }
        printf("]\n");
    }
}

Elem busca_valor(Lista li, int valor) {
    if (li == NULL || li->qtd == 0) return NULL;
    Elem aux = li->inicio;
    while (aux != NULL) {
        if (aux->valor == valor) return aux;
        aux = aux->prox;
    }
    printf("Não foi encontrado elemento com o valor %d\n", valor);
    return NULL;
}

Elem consulta_lista_posicao(Lista li, int pos) {
    if (li == NULL || li->qtd == 0) return NULL;
    Elem aux = li->inicio;
    int i = 0; //pra comparar a posição passada
    while (aux != NULL) {
        if (i == pos) return aux;
        aux = aux->prox;
        i++;
    }
    printf("Não há elementos na posição %d\n", i);
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

    insere_inicio(li, 1);
    insere_inicio(li, 2);
    insere_inicio(li, 3);
    remove_inicio(li);
    insere_final(li, 4);
    insere_final(li, 5);
    remove_final(li);

    printf("Lista vazia? R: %d\n", lista_vazia(li));
    printf("Qtd elem = %d\n", tamanho_lista(li));

    imprime_lista(li);
    imprime_lista_reverso(li);

    busca_valor(li, 3);
    busca_valor(li, 1);

    

    return 0;
}
