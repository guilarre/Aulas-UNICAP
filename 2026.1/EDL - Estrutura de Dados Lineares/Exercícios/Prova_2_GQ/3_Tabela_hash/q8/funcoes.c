#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

Tabela_hash cria_tabela() {
    Tabela_hash tabela = malloc(sizeof(struct tabela_hash));
    if (tabela == NULL) return NULL;

    tabela->qtd = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela->array[i] = -1;
    }

    return tabela;
}

int sondagem_linear(int chave, int i) {
    return (chave + i) % TABLE_SIZE;
}

int sondagem_quad(int chave, int i) {
    return (chave + i*i) % TABLE_SIZE;
}

int sondagem_quad_mod(int chave, int i) {
    return (chave + 2*i +i*i) % TABLE_SIZE;
}

int sondagem_hash_duplo(int chave, int i) {
    int h1 = chave % TABLE_SIZE;
    int h2 = 7 - (chave % 7);
    return (h1 + i * h2) % TABLE_SIZE;
}

int inserir_hash(Tabela_hash tabela, int chave, int metodo) {
    if (tabela == NULL || tabela->qtd == TABLE_SIZE) return 1;
    int i = 0;
    int pos;
    switch (metodo) {
        case 1:
            pos = sondagem_linear(chave, i);
            while (tabela->array[pos] != -1 && i < TABLE_SIZE) {
                i++;
                pos = sondagem_linear(chave, i);
            }
            break;
        case 2:
            pos = sondagem_quad(chave, i);
            while (tabela->array[pos] != -1 && i < TABLE_SIZE) {
                i++;
                pos = sondagem_quad(chave, i);
            }
            break;
        case 3:
            pos = sondagem_quad_mod(chave, i && i < TABLE_SIZE);
            while (tabela->array[pos] != -1) {
                i++;
                pos = sondagem_quad_mod(chave, i);
            }
            break;
        case 4:
            pos = sondagem_hash_duplo(chave, i && i < TABLE_SIZE);
            while (tabela->array[pos] != -1) {
                i++;
                pos = sondagem_hash_duplo(chave, i);
            }
            break;
    }
    tabela->array[pos] = chave;
    tabela->qtd++;
    return 0;
}

void printa_tabela(Tabela_hash tabela) {
    if (tabela != NULL && tabela->qtd != 0) {
        while ()
    }
}
