#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila {
    int inicio, fim, qtd;
    int *array;
    int array_max;
} *Fila;

Fila criar_fila(int array_max) {
    Fila f = malloc(sizeof(struct fila));
    if (f == NULL) return NULL;
    else {
        f->inicio = 0;
        f->fim = 0;
        f->qtd = 0;
        f->array_max = array_max;
        f->array = malloc(sizeof(int) * f->array_max);
        if (f->array == NULL) {
            free(f);
            return NULL;
        }
        return f;
    }
}

int inserir_fila(Fila f, int valor) {
    if (f == NULL || f->qtd >= f->array_max) return 1;
    else {
        f->array[f->fim] = valor;
        f->fim = (f->fim + 1) % f->array_max;
        f->qtd++;
        return 0;
    }
}

int remover_fila(Fila f) {
    if (f == NULL || f->qtd <= 0) return 1;
    else {
        f->inicio = (f->inicio + 1) % f->array_max;
        f->qtd--;
        return 0;
    }
}

int acessar_fila(Fila f, int *valor) {
    if (f == NULL || f->qtd <= 0) return 1;
    else {
        *valor = f->array[f->inicio];
        return 0;
    }
}

void destruir_fila(Fila f) {
    if (f == NULL) return;
    else {
        free(f->array);
        free(f);
    }
}

Fila copiar_fila(Fila f) {
    if (f == NULL) return NULL;
    else {
        Fila fcpy = criar_fila(f->array_max);
        if (fcpy == NULL) return NULL;
        fcpy->inicio = f->inicio;
        fcpy->fim = f->fim;
        fcpy->qtd = f->qtd;
        fcpy->array_max = f->array_max;
        memcpy(fcpy->array, f->array, sizeof(int) * fcpy->array_max);
        return fcpy;
    }
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
        destruir_fila(fcpy);
    }
}

int concat_into(Fila f1, Fila f2, Fila f3) {
    if (f1 == NULL || f2 == NULL || f3 == NULL) return 1;
    else {
        Fila f1cpy = copiar_fila(f1);
        Fila f2cpy = copiar_fila(f2);
        if (f1cpy == NULL || f2cpy == NULL) return 1;

        // merge sort
        int v1, v2;
        // Enquanto houver elementos em ambas as filas
        while (acessar_fila(f1cpy, &v1) == 0 && acessar_fila(f2cpy, &v2) == 0) {
            if (v1 <= v2) {
                inserir_fila(f3, v1);
                remover_fila(f1cpy);
            } else {
                inserir_fila(f3, v2);
                remover_fila(f2cpy);
            }
        }
        // Se sobrar elementos em F1 (F2 acabou)
        while (acessar_fila(f1cpy, &v1) == 0) {
            inserir_fila(f3, v1);
            remover_fila(f1cpy);
        }
        // Se sobrar elementos em F2 (F1 acabou)
        while (acessar_fila(f2cpy, &v2) == 0) {
            inserir_fila(f3, v2);
            remover_fila(f2cpy);
        }

        destruir_fila(f1cpy);
        destruir_fila(f2cpy);
        return 0;
    }
}

int main() {
    Fila f1 = criar_fila(5);
    Fila f2 = criar_fila(5);
    Fila f3 = criar_fila(10);

    inserir_fila(f1, 1);
    inserir_fila(f1, 2);
    inserir_fila(f1, 3);
    inserir_fila(f1, 4);
    inserir_fila(f1, 5);

    // inserir_fila(f2, 1);
    // inserir_fila(f2, 2);
    // inserir_fila(f2, 3);
    // inserir_fila(f2, 4);
    // inserir_fila(f2, 5);

    inserir_fila(f2, 0);
    inserir_fila(f2, 6);
    inserir_fila(f2, 7);
    inserir_fila(f2, 11);
    inserir_fila(f2, 90);

    printf("F1 = ");
    printa_fila(f1);
    printf("F2 = ");
    printa_fila(f2);

    concat_into(f1, f2, f3);
    printf("F3 = ");
    printa_fila(f3);

    return 0;
}
