#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 9

typedef struct no {
    int chave;
    struct no *prox;
} *No;

typedef struct tabela_hash {
    int qtd; //qtd total de elementos
    No array[TABLE_SIZE]; //array de elem encadeados
} *Tabela_hash;

Tabela_hash cria_tabela() {
    Tabela_hash tabela = malloc(sizeof(struct tabela_hash));
    if (tabela == NULL) return NULL;
    tabela->qtd = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela->array[i] = NULL;
    }
    return tabela;
}

// retorna índice
int funcao_hash(int chave) {
    int indice = chave % TABLE_SIZE;
    return indice;
}

int inserir_hash(int chave, Tabela_hash tabela) {
    if (tabela == NULL) return 1;
    No no = malloc(sizeof(struct no));
    if (no == NULL) return 1;
    no->chave = chave;
    int indice = funcao_hash(no->chave);
    if (tabela->array[indice] == NULL) { //se vazia
        no->prox = NULL;
        tabela->array[indice] = no;
    } else {
        No aux = tabela->array[indice];
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    tabela->qtd++;
    return 0;
}

void printa_tabela(Tabela_hash tabela) {
    if (tabela != NULL && tabela->qtd != 0) {
        printf("\n#########################\n");
        printf("###### Tabela hash ######\n\n");
        for (int i = 0; i < TABLE_SIZE; i++) {
            printf("tabela[%d]:\t", i);
            No aux = tabela->array[i];
            while (aux != NULL) {
                printf("%d ", aux->chave);
                aux = aux->prox;
            }
            printf("\n");
        }
        printf("\n#########################\n");
    }
}

void destroi_tabela(Tabela_hash tabela) {
    if (tabela != NULL && tabela->qtd != 0) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            No aux = tabela->array[i];
            No prox;
            while (aux != NULL) {
                prox = aux->prox;
                free(aux);
                aux = prox;
            }
        }
    }
    free(tabela);
}

int main() {
    Tabela_hash tabela = cria_tabela();

    inserir_hash(5, tabela);
    inserir_hash(28, tabela);
    inserir_hash(19, tabela);
    inserir_hash(15, tabela);
    inserir_hash(20, tabela);
    inserir_hash(33, tabela);
    inserir_hash(12, tabela);
    inserir_hash(7, tabela);
    inserir_hash(10, tabela);

    printa_tabela(tabela);

    destroi_tabela(tabela);

    return 0;
}
