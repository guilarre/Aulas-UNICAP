#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila {
    int inicio, fim, qtd;
    int *array;
    int arraymax;
} *Fila;

Fila criar_fila(int arraymax) {
    Fila f = malloc(sizeof(struct fila));
    if (f == NULL) return NULL;
    else {
        f->inicio = 0;
        f->fim = 0;
        f->qtd = 0;
        f->arraymax = arraymax;
        f->array = malloc(sizeof(int) * f->arraymax);
        if (f->array == NULL) {
            free(f);
            return NULL;
        }
        return f;
    }
    return NULL;
}

int inserir_fila(Fila f, int valor) {
    if (f == NULL || f->qtd >= f->arraymax) return 1;
    else {
        f->array[f->fim] = valor;
        f->fim = (f->fim + 1) % f->arraymax;
        f->qtd++;
        return 0;
    }
    return 1;
}

int remover_fila(Fila f) {
    if (f == NULL || f->qtd <= 0) return 1;
    else {
        f->inicio = (f->inicio + 1) % f->arraymax;
        f->qtd--;
        return 0;
    }
    return 1;
}

int acessar_fila(Fila f, int *valor) {
    if (f == NULL || f->qtd <= 0) return 1;
    else {
        *valor = f->array[f->inicio];
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
    if (f == NULL) return NULL;
    else {
        Fila fcpy = criar_fila(f->arraymax);
        if (fcpy == NULL) return NULL;
        fcpy->arraymax = f->arraymax;
        fcpy->inicio = f->inicio;
        fcpy->fim = f->fim;
        fcpy->qtd = f->qtd;
        memcpy(fcpy->array, f->array, fcpy->arraymax * sizeof(int));
        return fcpy;
    }
    return NULL;
}

void concatenar(Fila f1, Fila f2) {
    if (f1 == NULL || f2 == NULL) return;
    else {
        Fila fcat = criar_fila(f1->qtd + f2->qtd);
        if (fcat == NULL) return;
        Fila f1cpy = copiar_fila(f1);
        Fila f2cpy = copiar_fila(f2);
        if (f1cpy == NULL || f2cpy == NULL) {
            free(fcat);
            return;
        }

        int valor;
        while (acessar_fila(f1, &valor) == 0) {
            inserir_fila(fcat, valor);
            remover_fila(f1);
        }
        while (acessar_fila(f2, &valor) == 0) {
            inserir_fila(fcat, valor);
            remover_fila(f2);
        }
        free(f1);
        *f1 = *fcat; //aponta pro novo
        free(f1cpy);
        free(f2cpy);
    }
    return;
}

void printa_fila(Fila f) {
    if (f == NULL || f->qtd <= 0) return;
    else {
        Fila fcpy = copiar_fila(f);
        if (fcpy == NULL) return;
        int valor;
        while (acessar_fila(fcpy, &valor) == 0) {
            printf("%d ", valor);
            remover_fila(fcpy);
        }
        printf("\n");
    }
    return;
}

int main() {
    Fila f = criar_fila(5);
    Fila g = criar_fila(5);
    inserir_fila(f, 1);
    inserir_fila(f, 2);
    inserir_fila(f, 3);
    inserir_fila(f, 4);
    inserir_fila(f, 5);
    inserir_fila(g, 1);
    inserir_fila(g, 2);
    inserir_fila(g, 3);
    inserir_fila(g, 4);
    inserir_fila(g, 5);

    printf("## antes:\n");
    printf("f = ");
    printa_fila(f);
    printf("g = ");
    printa_fila(g);
    concatenar(f, g);
    printf("## depois:\n");
    printf("f = ");
    printa_fila(f);
    printf("g = ");
    printa_fila(g);

    return 0;
}
