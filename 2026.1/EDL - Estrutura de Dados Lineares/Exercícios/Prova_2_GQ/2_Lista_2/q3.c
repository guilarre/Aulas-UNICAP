#include <stdlib.h>
#include <stdio.h>

// Lista circular unicamente encadeada (onde o prox do último = primeiro)

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

typedef struct lista {
    int qtd;
    Elem final;
} *Lista;

Lista cria_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li == NULL) return NULL;
    li->qtd = 0;
    li->final = NULL;
    return li;
}

int insere_inicio(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    if (li->final == NULL) {
        no->prox = no;
        li->final = no;
    } else {
        no->prox = li->final->prox;
        li->final->prox = no;
    }
    li->qtd++;
    return 0;
}

int insere_final(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    if (li->final == NULL) {
        no->prox = no;
    } else {
        no->prox = li->final->prox;
        li->final->prox = no;
    }
    li->final = no;
    li->qtd++;
    return 0;
}

int remove_inicio(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    if (li->final->prox == li->final) { //só 1 elem
        free(li->final);
        li->final = NULL;
    } else {
        Elem prox = li->final->prox->prox;
        free(li->final->prox);
        li->final->prox = prox;
    }
    li->qtd--;
    return 0;
}

int remove_final(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    if (li->final->prox == li->final) { //só 1 elem
        free(li->final);
        li->final = NULL;
    } else {
        Elem aux = li->final->prox;
        Elem ant;
        while (aux->prox != li->final->prox) {
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = aux->prox;
        free(aux);
        li->final = ant;
    }
    li->qtd--;
    return 0;
}

void imprime_lista(Lista li) {
    if (li != NULL && li->qtd != 0) {
        Elem aux = li->final->prox;
        printf("Elementos = [ ");
        do {
            printf("%d ", aux->valor);
            aux = aux->prox;
        } while (aux != li->final->prox);
        printf("]\n");
    }
}

void imprime_lista_reverso(Lista li) {
    if (li != NULL && li->qtd != 0) {
        int *pilha = malloc(sizeof(int) * li->qtd);
        int topo = -1;
        Elem aux = li->final->prox;
        do {
            pilha[++topo] = aux->valor;
            aux = aux->prox;
        } while (aux != li->final->prox);

        printf("Elementos invertidos = [ ");
        for (int i = 0; i < li->qtd; i++) {
            printf("%d ", pilha[topo--]);
        }
        printf("]\n");
    }
}

Elem busca_valor(Lista li, int valor) {
    if (li == NULL || li->qtd == 0) return NULL;
    Elem aux = li->final->prox;
    while (aux != li->final) {
        if (aux->valor == valor) return aux;
        aux = aux->prox;
    }
    printf("ERRO: Não foi encontrado o valor '%d' na lista\n", valor);
    return NULL;
}

Elem consulta_lista_posicao(Lista li, int pos) {
    if (li == NULL || li->qtd == 0) return NULL;
    Elem aux = li->final->prox;
    int i = 0;
    while (aux != li->final) {
        if (i == pos) return aux;
        i++;
        aux = aux->prox;
    }
    printf("ERRO: Não há elemento na posição '%d'\n", pos);
    return NULL;
}

int lista_vazia(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    return 0;
}

int tamanho_lista(Lista li) {
    if (li == NULL || li->qtd == 0) return 0;
    return li->qtd;
}

void libera_lista(Lista li) {
    if (li != NULL) {
        if (li->qtd != 0) {
            Elem aux = li->final->prox;
            Elem prox;
            for (int i = 0; i < li->qtd; i++) {
                prox = aux->prox;
                free(aux);
                aux = prox;
            }
        }
        free(li);
    }
}

int main() {
    Lista li = cria_lista();

    printf("Lista vazia? R: %d\n", lista_vazia(li));

    printf("Inserindo elementos...\n");
    insere_inicio(li, 1);
    insere_inicio(li, 2);
    insere_inicio(li, 3);
    insere_inicio(li, 4);
    remove_final(li);
    insere_final(li, 5);
    insere_final(li, 6);
    insere_final(li, 7);
    insere_final(li, 8);
    remove_inicio(li);

    printf("Lista vazia? R: %d\n", lista_vazia(li));
    printf("Tamanho da lista = %d\n", tamanho_lista(li));

    imprime_lista(li);
    imprime_lista_reverso(li);

    busca_valor(li, 2);
    busca_valor(li, 3);
    Elem no_consulta = consulta_lista_posicao(li, 3);
    if (no_consulta) printf("Valor do elemento consultado: '%d'\n", no_consulta->valor);
    no_consulta = consulta_lista_posicao(li, 9);
    if (no_consulta) printf("Valor do elemento consultado: '%d'\n", no_consulta->valor);

    libera_lista(li);

    return 0;
}
