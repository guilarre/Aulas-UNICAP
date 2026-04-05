#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct pilha {
    int topo;
    int elementos[MAX]; 
} *Pilha;

Pilha criar_pilha() {
    Pilha p = malloc(sizeof(struct pilha));
    if (p == NULL) return NULL;
    p->topo = 0;
    return p;
}

int push(Pilha p, int valor) {
    if (p == NULL || p->topo == MAX) return 1;
    p->elementos[p->topo++] = valor;
    return 0;
}

int pop(Pilha p) {
    if (p == NULL || p->topo <= 0) return 1;
    p->topo--;
    return 0;
}

int peek(Pilha p, int *valor) {
    if (p == NULL || p->topo <= 0) return 1;
    *valor = p->elementos[p->topo-1];
    return 0;
}

int tamanho(Pilha p) {
    if (p == NULL) return 0;
    return p->topo;
}

int inverter_pilha(Pilha p) {
    Pilha aux = malloc(sizeof(struct pilha));
    if (aux == NULL) return 1;

    int erro = 0;
    int elem;
    while (erro == 0) {
        peek(p, &elem);
        push(aux, elem);
        erro = pop(p);
    }

    // Altera diretamente a pilha p passada, descartando aux
    *p = *aux; // NOTE: TEM que ser assim, passando os dados
    free(aux);
    return 0;
}

int main() {
    Pilha p = criar_pilha();
    if (p == NULL) return 1;

    //popular pilha
    int num;
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &num);
        push(p, num);
    }

    inverter_pilha(p);

    //printa pilha
    int j = tamanho(p);
    for (int i = 0; i < j; i++) {
        peek(p, &num);
        printf("%d ", num);
        pop(p);
    }
    printf("\n");

    free(p);
    return 0;
}
