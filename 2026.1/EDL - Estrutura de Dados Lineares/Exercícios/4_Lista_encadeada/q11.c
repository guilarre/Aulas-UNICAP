#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento *prox;
} *Elem;

typedef struct lista {
    int qtd;
    Elem inicio;
} *Lista;

Lista criar_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li == NULL) return NULL;
    li->qtd = 0;
    li->inicio = NULL;
    return li;
}

int inserir_inicio(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    no->valor = valor;
    no->prox = li->inicio; // TODO: algo assim? to morto dmais p lembrar
}

int main() {
    return 0;
}
