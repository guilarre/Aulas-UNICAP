#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct fila {
    int inicio, fim, qtd; //qtd opcional
    int vetor[MAX];
} *Fila;

Fila criar_fila() {
    Fila f = malloc(sizeof(struct fila));
    if (f == NULL) return NULL;
    else {
        f->inicio = 0;
        f->fim = 0;
        f->qtd = 0;
        return f;
    }
}

int inserir_fila(Fila f, int valor) {
    if (f == NULL || f->qtd >= MAX) return 1;
    else {
        f->vetor[f->fim] = valor;
        f->fim = (f->fim + 1) % MAX; // NOTE: LEMBRAR DISSO
        f->qtd++;
        return 0;
    }
    return 1;
}

int remover_fila(Fila f) {
    if (f == NULL || f->qtd <= 0) return 1;
    else {
        f->inicio = (f->inicio + 1) % MAX; // NOTE: LEMBRAR DISSO
        f->qtd--;
        return 0;
    }
    return 1;
}

int acessar(Fila f, int *valor) {
    if (f == NULL || f->qtd <= 0) return 1;
    else {
        *valor = f->vetor[f->inicio];
        return 0;
    }
    return 1;
}

int tamanho(Fila f) {
    if (f == NULL || f->qtd <= 0) return 0;
    else {
        return f->qtd;
    }
    return 0;
}

void destruir_fila(Fila f) {
    if (f == NULL) return;
    else {
        free(f);
    }
    return;
}

Fila copiar_fila(Fila f) {
    if (f == NULL || f->qtd <= 0) return NULL;
    else {
        Fila cpy = criar_fila();
        cpy->qtd = f->qtd;
        cpy->inicio = f->inicio;
        cpy->fim = f->fim;
        memcpy(cpy->vetor, f->vetor, MAX * sizeof(int));
        return cpy;
    }
    return NULL;
}

// int acessar_fim(Fila f, int *valor) {
//     if (f == NULL || f->qtd <= 0) return 1;
//     else {
//         *valor = f->vetor[(f->fim-1) % MAX];
//         return 0;
//     }
//     return 1;
// }

Fila reverso(Fila f) {
    if (f == NULL || f->qtd <= 0) return NULL;
    else {
        Fila fcpy = copiar_fila(f);
        if (fcpy == NULL) return NULL;
        Fila rev = criar_fila();
        if (rev == NULL) {
            free(fcpy);
            return NULL;
        }

        //insere em uma pilha
        int valor, pilha[MAX], topo = 0;
        while (acessar(fcpy, &valor) == 0) {
            pilha[topo++] = valor;
            remover_fila(fcpy);
        }
        // inserir da pilha -> lista (invertendo no processo)
        while (topo != 0) {
            valor = pilha[topo-1];
            inserir_fila(rev, valor);
            topo--;
        }

        free(fcpy);
        return rev;
    }
    return NULL;
}

int main() {
    Fila f = criar_fila();
    inserir_fila(f, 1);
    inserir_fila(f, 2);
    inserir_fila(f, 3);
    remover_fila(f);
    inserir_fila(f, 4);
    remover_fila(f);
    inserir_fila(f, 5);
    inserir_fila(f, 6);
    inserir_fila(f, 7);

    int valor;
    while (acessar(f, &valor) == 0) {
        printf("%d ", valor);
        remover_fila(f);
    }
    printf("\n");

    inserir_fila(f, 1);
    inserir_fila(f, 2);
    inserir_fila(f, 3);
    remover_fila(f);
    inserir_fila(f, 4);
    remover_fila(f);
    inserir_fila(f, 5);
    inserir_fila(f, 6);
    inserir_fila(f, 7);
    Fila rev = reverso(f);
    if (rev != NULL) {
        while (acessar(rev, &valor) == 0) {
            printf("%d ", valor);
            remover_fila(rev);
        }
        printf("\n");
    }

    destruir_fila(f);
    destruir_fila(rev);
    return 0;
}
