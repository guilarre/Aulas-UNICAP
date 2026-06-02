#include <stdio.h>
#include <stdlib.h>

// NOTE: exemplo pra lista parecida com a do projeto
//
// typedef struct {
//     char *nome;
//     char *email;
//     float nota;
// } No;
//
// typedef struct {
//     int qtd;
//     int table_size;
//     No array[table_size];
// } Tabela;

typedef struct tabela_hash {
    int **itens;
    int table_size;
    int qtd; //qtd de elementos na tabela em um dado momento
} *Tabela_hash;

Tabela_hash cria_tabela(int size) {
    Tabela_hash th = malloc(sizeof(struct tabela_hash));
    if (th != NULL) {
        th->table_size = size;
        th->qtd = 0;
        th->itens = malloc(size * sizeof(int*)); // CHECK: pq dá erro ao botar *int em vez de int*
        if (th->itens != NULL) {
            for (int i = 0; i < size; i++)
                th->itens[i] = NULL;
        }
    }
    return th;
}

// TODO: cria_hash
int chave_divisao(int chave, int size) {
    // if (chave < 0) chave *= -1; //se entrassem valores negativos
    return chave % size;
}

int insere_hash(Tabela_hash th, int valor) {
    if (th == NULL || th->qtd == th->table_size) return 1;
    int *novo = malloc(sizeof(int));
    *novo = valor;

    int pos = chave_divisao(valor, th->table_size);
    if (th->itens[pos] == NULL) {
        th->itens[pos] = novo;
        th->qtd++;
    } else {
        free(th->itens[pos]);
        th->itens[pos] = novo;
        // NOTE: qtd continua igual

        // se fosse lidar com colisão seria algo assim (CHECK: falta logica de qnd tiver removido vs null)
        // while (th->itens[pos] == NULL)
        //     pos++;
        // th->itens[pos] = novo;

    }
    return 0;
}

// NOTE: chave pode ser email e valor algum dado por ex., mas aqui é a mesma coisa
int busca_hash(Tabela_hash th, int chave, int *valor) {
    if (th == NULL) return 1;
    int pos = chave_divisao(chave, th->table_size);
    if (th->itens[pos] == NULL) return 1;
    *valor = *(th->itens[pos]);
    return 0;
}

void imprime_hash(Tabela_hash th) {
    if (th == NULL) return;
    for (int i = 0; i < th->table_size; i++) {
        if (th->itens[i] == NULL) printf("%d [ ]\n", i);
        else {
            printf("%d [%d]\n", i, *th->itens[i]);
        }
    }
}

int main() {
    Tabela_hash th = cria_tabela(11);
    int elemento = 11;
    insere_hash(th, elemento);
    insere_hash(th, 13);
    insere_hash(th, 16);
    insere_hash(th, 33); //vai sobrescrever

    int valor;
    elemento = 12;
    if (busca_hash(th, elemento, &valor)) printf("Chave %d não encontrada\n", elemento);
    printf("Elemento encontrado = %d\n", valor);

    imprime_hash(th);
    printf("\nQtd = %d\n", th->qtd);
    return 0;
}
