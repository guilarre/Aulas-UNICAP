#include "q4.h"
#include <assert.h>
#include <stdio.h>

struct complexo {
    float x;
    float y;
};

// Complexo = ponteiro para struct complexo

Complexo criar_complexo(float x, float y) {
    Complexo c = malloc(sizeof(struct complexo));
    if (c != NULL) {
        c->x = x;
        c->y = y;
    }
    return c;
}

void destruir_complexo(Complexo c) {
    if (c != NULL)
        free(c);
}

Complexo somar_complexos(Complexo c1, Complexo c2) {
    float x = c1->x + c2->x;
    float y = c1->y + c2->y;

    Complexo c3 = malloc(sizeof(struct complexo));

    c3->x = x;
    c3->y = y;

    return c3;
}

Complexo subtrair_complexos(Complexo c1, Complexo c2) {
    float x = c1->x - c2->x;
    float y = c1->y - c2->y;

    Complexo c3 = malloc(sizeof(struct complexo));

    c3->x = x;
    c3->y = y;

    return c3;
}

Complexo multiplicar_complexos(Complexo c1, Complexo c2) {
    float x1 = c1->x;
    float y1 = c1->y;
    float x2 = c2->x;
    float y2 = c2->y;

    Complexo c3 = malloc(sizeof(struct complexo));

    c3->x = x1*x2 - y1*y2;
    c3->y = x1*y2 + x2*y1;

    return c3;
}

Complexo dividir_complexos(Complexo c1, Complexo c2) {
    float x1 = c1->x;
    float y1 = c1->y;
    float x2 = c2->x;
    float y2 = c2->y;

    float denominador = x2*x2 + y2*y2;
    assert(denominador != 0);
    Complexo c3 = malloc(sizeof(struct complexo));

    c3->x = (x1*x2 + y1*y2) / denominador;
    c3->y = (x2*y1 - x1*y2) / denominador;

    return c3;
}

void printa_complexo(Complexo c1) {
    printf("x = %f\n", c1->x);
    printf("y = %f\n", c1->y);
}
