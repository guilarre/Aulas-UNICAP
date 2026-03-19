// Lista encadeada (dinâmica)
// criar
// inserir_inicio
// remover_inicio
// acessar_inicio
// destruir

#include <stdlib.h>
#include <stdio.h>

typedef struct elemento {
    int valor;
    struct elemento* prox;
} Elem;

typedef struct lista {
    struct elemento* inicio;
} Lista;

Lista* criar_lista() {
    Lista* l = malloc(sizeof(Lista));
    if (l != NULL) {
        li->inicio = NULL;
        return l;
    }
}

int inserir_inicio(Lista* li, int valor) {
    if (li != NULL) {
        Elem* no = li->inicio;
        no->valor = valor;
        no->prox = li->inicio;
        li->inicio = no;
        return 0;
    }
    // falta se a lista estiver vazia
    return 1;
}

int remover_inicio(Lista* li) {
    if (li->inicio != NULL) {
        Elem* no = li->inicio;
        li->inicio = no->prox;
        free(no);
        return 0;
    }
    return 1;
}

int acessar_inicio(Lista* li, int* valor) {
    if (li != NULL) {
        *valor = li->inicio->valor;
    }
    return 1;
}

void destruir(Lista* li) {
    if (li != NULL) {
        Elem* no = li->inicio;
        while (no != NULL) {
            Elem* prox = no->prox;
            free(no);
            no = prox;
        }
        free(li);
    }
}

int main() {
    Lista* li = criar_lista();
    
    inserir_inicio(li, 20);
    inserir_inicio(li, 30);
    inserir_inicio(li, 40);
    
    int valor;
    acessar_inicio(li, &valor);
    printf("O valor do início é: %d", valor);

    return 0;
}
