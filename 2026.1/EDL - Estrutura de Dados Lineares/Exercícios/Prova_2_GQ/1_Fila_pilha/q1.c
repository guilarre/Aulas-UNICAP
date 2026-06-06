#include <stdlib.h>
#include <stdio.h>

// Fila = FIFO (insere no fim, retira no início)

typedef struct elemento {
    int valor;
    struct elemento *prox;
} *Elem;

typedef struct fila {
    int qtd;
    Elem inicio, final;
} *Fila;

Fila cria_fila() {
    Fila f = malloc(sizeof(struct fila));
    if (f == NULL) return NULL;
    f->qtd = 0;
    f->inicio = NULL;
    f->final = NULL;
    return f;
}

int enfileira(Fila f, int valor) {
    if (f == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    no->prox = NULL; //sempre vai ser nulo pq vai pro fim
    if (f->inicio == NULL) { //se tiver vazia
        f->inicio = no;
        f->final = no;
    } else { // se já tiver elementos
        f->final->prox = no; //próx do final antigo
f->final = no; //fim da fila
    }
    f->qtd++;
    return 0;
}

// só tira e não retorna o valor retirado
int desenfileira(Fila f) {
    if (f == NULL || f->inicio == NULL) return 1;
    if (f->inicio->prox == NULL) { //só tem 1 elem na fila
        free(f->inicio);
        f->inicio = NULL;
        f->final = NULL;
    } else { //mais de um elem na fila
        Elem aux = f->inicio->prox; //novo início
        free(f->inicio);
        f->inicio = aux;
    }
    f->qtd--;
    return 0;
}

int frente(Fila f, int *valor) {
    if (f == NULL || f->qtd == 0) return 1;
    *valor = f->inicio->valor;
    return 0;
}

int tamanho(Fila f) {
    if (f == NULL || f->qtd == 0) return 0;
    return f->qtd;
}

int fila_vazia(Fila f) {
    if (f == NULL || f->qtd == 0) return 1; //sim
    return 0;
}

void imprime_fila(Fila f) {
    if (f != NULL) {
        Elem aux = f->inicio;
        printf("Elementos da fila:\n[ ");
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("]\n");
    }
}

void libera_fila(Fila f) {
    if (f != NULL) {
        Elem aux = f->inicio;
        Elem ant;
        while (aux != NULL) {
            ant = aux;
            aux = aux->prox;
            free(ant);
        }
        free(f);
    }
}

// TEST:
int main() {
    Fila f = cria_fila();
    printf("Fila vazia? R.: %d\n", fila_vazia(f));

    enfileira(f, 1);
    enfileira(f, 2);
    enfileira(f, 3);
    enfileira(f, 4);

    desenfileira(f);

    imprime_fila(f);

    printf("Tamanho da fila = %d\n", tamanho(f));

    int valor;
    if (!frente(f, &valor)) {
        printf("Primeiro da fila = %d\n", valor);
    }

    libera_fila(f);
    return 0;
}
