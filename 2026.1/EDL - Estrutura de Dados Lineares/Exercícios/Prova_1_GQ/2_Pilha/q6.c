#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct pilha {
    int topo;
    char array[MAX];
} *Pilha;

Pilha criar_pilha() {
    Pilha p = malloc(sizeof(struct pilha));
    if (p == NULL) return NULL;
    p->topo = 0;
    return p;
}

int push(Pilha p, char c) {
    if (p == NULL || p->topo >= MAX) return 1;
    p->array[p->topo++] = c;
    return 0;
}

int pop(Pilha p) {
    if (p == NULL || p->topo <= 0) return 1;
    p->topo--;
    return 0;
}

int peek(Pilha p, char *c) {
    if (p == NULL || p->topo <= 0) return 1;
    *c = p->array[p->topo-1]; //topo aponta pra prox pos
    return 0;
}

Pilha copiar_pilha(Pilha p) {
    if (p == NULL) return NULL;
    Pilha p_copy = criar_pilha();
    if (p_copy == NULL) return NULL;
    p_copy->topo = p->topo;
    memcpy(p_copy->array, p->array, MAX);
    return p_copy;
}

Pilha inverter_pilha(Pilha p) {
    if (p == NULL || p->topo <= 0) return NULL;
    Pilha p_copy = copiar_pilha(p); //copia pra n alterar o orig
    if (p_copy == NULL) return NULL;
    Pilha aux = criar_pilha(); //aux vazia
    if (aux == NULL) {
        free(p_copy);
        return NULL;
    }

    char c;
    while (peek(p_copy, &c) == 0) { //inserir em aux
        push(aux, c);
        pop(p_copy);
    }

    free(p_copy);
    return aux;
}

int palindromo(Pilha p) { // 0 = ñ, 1 = s, -1 = erro
    if (p == NULL || p->topo <= 0) return -1;
    Pilha p_copy = copiar_pilha(p);
    if (p_copy == NULL) return -1;
    Pilha p_inv = inverter_pilha(p);
    if (p_inv == NULL) {
        free(p_copy);
        return -1;
    }

    char c_p, c_inv;
    int pal = 1;
    while (peek(p_copy, &c_p) == 0 && peek(p_inv, &c_inv) == 0) {
        if (c_p != c_inv) {
            pal = 0; //se não
            break;
        }
        pop(p_copy);
        pop(p_inv);
    }
    free(p_copy);
    free(p_inv);
    return pal;
}

// void printa_str(Pilha p) {
//     if (p == NULL || p->topo == 0) return;
//     printf("%s\n", p->array);
// }

void printa_pilha(Pilha p) {
    if (p == NULL || p->topo == 0) return;
    Pilha p_copy = copiar_pilha(p);
    if (p_copy == NULL) return;

    char c;
    while (peek(p_copy, &c) == 0) {
        printf("%c", c);
        pop(p_copy);
    }
    printf("\n");

    free(p_copy);
}

int main() {
    char s[20];
    fgets(s, 20, stdin); //recebo do user
    s[strcspn(s, "\n")] = '\0'; //tira '\n'

    Pilha p = criar_pilha();

    int i = 0;
    while (s[i] != '\0') {
        push(p, s[i]);
        i++;
    }

    //DEBUG
    // printf("%s ", s);
    // printa_pilha(p);
    // printa_pilha(inverter_pilha(p));

    int palind_val = palindromo(p);
    if (palind_val == 1) printf("É palíndromo\n");
    else if (palind_val == 0) printf("Não é palíndromo\n");
    else printf("error\n");

    free(p);
    return 0;
}
