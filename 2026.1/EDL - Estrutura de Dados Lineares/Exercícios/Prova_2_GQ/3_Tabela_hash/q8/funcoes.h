#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct tabela_hash {
    int qtd;
    int array[TABLE_SIZE];
} *Tabela_hash;

Tabela_hash cria_tabela();
int inserir_hash(Tabela_hash tabela, int valor, int metodo);
int sondagem_linear(int chave, int i);
int sondagem_quad(int chave, int i);
int sondagem_quad_mod(int chave, int i);
int sondagem_hash_duplo(int chave, int i);
void printa_tabela(Tabela_hash tabela);
