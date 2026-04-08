#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento *prox;
} *Elem;

typedef struct lista {
    int qtd;
    Elem inicio;
} *Lista;

Lista criar_lista();
int inserir_inicio(Lista li, int valor);
int inserir_fim(Lista li, int valor);
int remover_inicio(Lista li);
int remover_fim(Lista li);
int tamanho_lista(Lista li);
void destruir_lista(Lista li);
void printar_lista(Lista li);
