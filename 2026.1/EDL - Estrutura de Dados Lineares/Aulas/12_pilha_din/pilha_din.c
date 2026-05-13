#include <stdlib.h>
#include <stdio.h>

typedef struct elemento {
    int valor;
    struct elemento *prox;
} *Elem;

typedef struct pilha {
    int qtd;
    Elem topo;
} *Pilha;

Pilha criar_pilha() {
    Pilha p = malloc(sizeof(struct pilha));
    if (p == NULL) return NULL;
    p->qtd = 0;
    p->topo = NULL;
    return p;
}

int push(Pilha p, int valor) {
    if (p == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no == NULL) return 1;
    no->valor = valor;
    if (p->qtd == 0) { // caso seja vazia
        no->prox = NULL;
    } else { // caso tenha um elem ou mais
        no->prox = p->topo;
    }
    p->topo = no;
    p->qtd++;
    return 0;
}

int pop(Pilha p) {
    if (p == NULL || p->qtd == 0) return 1;
    if (p->topo->prox == NULL) { // caso só tenha 1 elem
        free(p->topo);
        p->topo = NULL;
    } else { // caso mais de 1
        Elem aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
    p->qtd--;
    return 0;
}

int peek(Pilha p, int *valor) {
    if (p == NULL || p->qtd == 0) return 1;
    *valor = p->topo->valor;
    return 0;
}

int size(Pilha p) {
    if (p == NULL) return 0;
    return p->qtd;
}

void destroy(Pilha p) {
    if (p == NULL) return;
    Elem aux;
    while (p->topo != NULL) {
        pop(p);
    }
    free(p);
}

// Tarefa: dada uma pilha de int, retorne o menor valor
// da pilha, mantendo a pilha original intacta.
int menor_valor(Pilha p, int *menor_valor) {
    if (p == NULL || p->qtd == 0) return 1;
    Elem aux = p->topo;
    int menor = aux->valor;
    while (aux != NULL) {
        if (aux->valor < menor) menor = aux->valor;
        aux = aux->prox;
    }
    *menor_valor = menor;
    return 0;
}

// TODO: implementação de menor_valor usando somente as funções
// (sem acessar diretamente a pilha)

int main() {
    Pilha p = criar_pilha();
    push(p, 1);
    push(p, 2);
    push(p, 3);

    int valor;
    if (!menor_valor(p, &valor)) printf("O menor valor é: %d\n", valor);

    peek(p, &valor);
    printf("%d\n", valor);
    pop(p);
    peek(p, &valor);
    printf("%d\n", valor);
    pop(p);
    peek(p, &valor);
    printf("%d\n", valor);
    pop(p);
    if (pop(p)) printf("can't pop any longer lol\n");

    destroy(p);

    return 0;
}
