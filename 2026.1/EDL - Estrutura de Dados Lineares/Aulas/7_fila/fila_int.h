#define MAX 5
#include <stdio.h>
#include <stdlib.h>

typedef struct fila *Fila;

Fila cria_fila();
int inserir_fila(Fila f, int valor);
int remover_fila(Fila f);
int acessar(Fila f, int* valor);
int tamanho(Fila f);
void destruir_fila(Fila f);
