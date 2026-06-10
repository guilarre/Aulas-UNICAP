#include "funcoes.h"

int main() {
    printf("Criando uma tabela hash...\n");
    Tabela_hash tabela = cria_tabela();

    printf("Inserindo elementos novos...\n");
    inserir_hash(tabela, 371, 1);
    inserir_hash(tabela, 121, 1);
    inserir_hash(tabela, 173, 1);
    inserir_hash(tabela, 203, 1);
    inserir_hash(tabela, 11, 1);
    inserir_hash(tabela, 24, 1);

    printf("###### SONDAGEM LINEAR #####\n");
    printa_tabela(tabela);

    printf("Criando tabela nova...\n");
    destroi_tabela(tabela);
    tabela = cria_tabela();
    printa_tabela(tabela);

    printf("Inserindo elementos novos...\n");
    inserir_hash(tabela, 371, 2);
    inserir_hash(tabela, 121, 2);
    inserir_hash(tabela, 173, 2);
    inserir_hash(tabela, 203, 2);
    inserir_hash(tabela, 11, 2);
    inserir_hash(tabela, 24, 2);

    printf("#### SONDAGEM QUADRÁTICA ###\n");
    printa_tabela(tabela);

    printf("Criando tabela nova...\n");
    destroi_tabela(tabela);
    tabela = cria_tabela();
    printa_tabela(tabela);

    printf("Inserindo elementos novos...\n");
    inserir_hash(tabela, 371, 3);
    inserir_hash(tabela, 121, 3);
    inserir_hash(tabela, 173, 3);
    inserir_hash(tabela, 203, 3);
    inserir_hash(tabela, 11, 3);
    inserir_hash(tabela, 24, 3);

    printf("## SONDAGEM QUADRÁTICA (MOD)\n");
    printa_tabela(tabela);

    printf("Criando tabela nova...\n");
    destroi_tabela(tabela);
    tabela = cria_tabela();
    printa_tabela(tabela);

    printf("Inserindo elementos novos...\n");
    inserir_hash(tabela, 371, 4);
    inserir_hash(tabela, 121, 4);
    inserir_hash(tabela, 173, 4);
    inserir_hash(tabela, 203, 4);
    inserir_hash(tabela, 11, 4);
    inserir_hash(tabela, 24, 4);

    printf("#### SONDAGEM HASH DUPLO ###\n");
    printa_tabela(tabela);

    destroi_tabela(tabela);

    return 0;
}
