#include <stdlib.h>
#include "circulo.h"
#define pi 3.14

struct Circulo {
    float r;
};

Circulo cria_circulo(float r) {
    if (r < 0)
        r *= -1;

    Circulo c = malloc(sizeof(struct Circulo));
    if (c != NULL)
        c->r = r;
    
    return c;
}

void destroi_circulo(Circulo c) {
    free(c);
}

float acessa_raio(Circulo c) {
    return c->r;
}

float calcula_area(Circulo c) {
    return pi * (c->r * c->r);
}

float calcula_perimetro(Circulo c) {
    return 2 * pi * c->r;
}