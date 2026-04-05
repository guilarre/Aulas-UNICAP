#include <stdlib.h>
#include <stdio.h>
#define MAX 20

typedef struct pilha {
    int topo;
    char expr[MAX]; //string da expressão
} *Pilha;

Pilha criar_pilha() {
    Pilha p = malloc(sizeof(struct pilha));
    if (p == NULL) return NULL;
    p->topo = 0;
    return p;
}

int pop(Pilha p) {
    if (p == NULL) return 1;
    if (p->topo <= 0) return 1;
    p->topo--;
    return 0;
}

int push(Pilha p, char c) {
    if (p == NULL) return 1;
    if (p->topo == MAX) return 1;
    p->expr[p->topo++] = c;
    return 0;
}

int peek(Pilha p, char *c) {
    if (p == NULL || p->topo == 0) return 1;
    *c = p->expr[p->topo-1];
    return 0;
}

int tamanho(Pilha p) {
    if (p == NULL) return 0;
    return p->topo;
}

int main() {
    Pilha p = criar_pilha();

    printf("Digite a expressão: ");
    //inserindo a expressão
    char c;
    int erro = 0;
    while (scanf("%c", &c) == 1 && c != '\n') {
        if (c == '(') {
            push(p, c);
        } else if (c == ')') {
            if (tamanho(p) == 0) {
                erro = 1; //fecha sem estar aberto
                break;
            }
            pop(p); //descarta o correspondente
        }
    }

    if (!erro && tamanho(p) == 0) printf("OK\n"); else printf("ERRADO\n");

    free(p);
    return 0;
}
