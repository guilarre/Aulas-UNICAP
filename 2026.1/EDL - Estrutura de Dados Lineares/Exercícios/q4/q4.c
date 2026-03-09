#include "q4.h"
#include <stdio.h>

struct complexo {
    float x;
    float y; // coeficiente de i
    int p; // potência de i
};

Complexo criar_complexo() {
    Complexo c = malloc(sizeof(struct complexo));
    if (c != NULL) {
        printf("Insira um número complexo (x + yi)\n");
        printf("Digite a parte real: ");
        scanf("%f", &c->x);
        printf("Digite o coeficiente de i: ");
        scanf("%f", &c->y);
        printf("Digite a potência de i (apenas números inteiros): ");
        scanf("%d", &c->p);
    }

    return c;
}

void destruir_completo(Complexo c) {
    if (c != NULL)
        free(c);
}

int somar_complexos(Complexo c1, Complexo c2, Complexo c3) {
    if (c1 == NULL || c2 == NULL)
        return 1;

    float x = c1->x + c2->x;
    float y = c1->y + c2->y;

    c3->x = x;
    c3->y = y;

    return 0;
}

int subtrair_complexo(Complexo c1, Complexo c2, Complexo c3) {
    if (c1 == NULL || c2 == NULL)
        return 1;

    float x = c1->x - c2->x;
    float y = c1->y - c2->y;

    c3->x = x;
    c3->y = y;

    return 0;
}

int multiplicar_complexo(Complexo c1, Complexo c2, Complexo c3) {
    if (c1 == NULL || c2 == NULL)
        return 1;

    float x1 = c1->x;
    float x2 = c2->x;
    float y1 = c1->y;
    float y2 = c2->y;
    float p1 = c1->p;
    float p2 = c2->p;

    float expr = (x1 + y1) * (x2 + y2);

    c3->x = x;
    c3->y = y;

    return 0;
}

int dividir_complexo(Complexo c1, Complexo c2, Complexo c3);
