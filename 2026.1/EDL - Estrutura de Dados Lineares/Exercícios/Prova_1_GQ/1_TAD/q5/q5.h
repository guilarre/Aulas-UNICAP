#include <stdlib.h>
#include <stdio.h>

typedef struct conjunto {
    int *elementos; // vetor
    int tamanho;
    int capacidade;
} *Conjunto;

Conjunto criar_conjunto(int capacidade); // cria conjunto vazio
int pertence(Conjunto A, int elemento);
int inserir(Conjunto A, int elemento);
int remover(Conjunto A, int elemento);
Conjunto uniao(Conjunto A, Conjunto B);
Conjunto intersecao(Conjunto A, Conjunto B);
Conjunto diferenca(Conjunto A, Conjunto B);
int sao_iguais(Conjunto A, Conjunto B);
void menor(Conjunto A, int *elemento);
void maior(Conjunto A, int *elemento);
int tamanho(Conjunto A);
int vazio_teste(Conjunto A);
