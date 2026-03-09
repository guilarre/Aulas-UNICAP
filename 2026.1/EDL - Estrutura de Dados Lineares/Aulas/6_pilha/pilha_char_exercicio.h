#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct pilha *Pilha;

Pilha criar_pilha();
int push(Pilha p, char dado);
int peek(Pilha p, char* dado);
int pop(Pilha p);
int tamanho_pilha(Pilha p);
void destruir_pilha(Pilha p);
Pilha copiar_pilha(Pilha p);
