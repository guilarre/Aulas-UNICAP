#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    struct elemento *prox;
    int valor;
} *Elem;

typedef struct lista {
    Elem inicio;
    int qtd;
} *Lista;

Lista criar_lista();
void destruir_lista(Lista li);
int tamanho_lista(Lista li);
int inserir_inicio(Lista li, int valor);
int inserir_fim(Lista li, int valor);
int remover_inicio(Lista li);
int remover_fim(Lista li);
int mod_elem(Lista li, int pos, int valor_novo);
void printar_lista(Lista li);
int soma_1_2_ult(Lista li, int *total);
