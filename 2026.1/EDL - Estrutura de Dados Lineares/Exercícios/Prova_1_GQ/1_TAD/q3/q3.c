// TAD para cilindro

// criar_cilindro()
// altura_cilindro()
// raio_cilindro()
// calcula_area()
// calcula_volume()
// destruir_cilindro()

#include "q3.h"

struct cilindro {
    float altura;
    float raio;
};

Cilindro criar_cilindro() {
    Cilindro c = malloc(sizeof(struct cilindro));
    float altura, raio;

    printf("Insira a altura do cilindro: ");
    scanf("%f", &altura);
    printf("Insira o raio do cilindro: ");
    scanf("%f", &raio);

    if (altura < 0)
        altura *= -1;
    if (raio < 0)
        raio *= -1;
 
    if (c != NULL) {
        c->altura = altura;
        c->raio = raio;
    }

    return c;
}

int altura_cilindro(Cilindro c, float *altura) {
    if (c != NULL) {
        *altura = c->altura;
        return 0;
    }
    return 1;
}

int raio_cilindro(Cilindro c, float *raio) {
    if (c != NULL) {
        *raio = c->raio;
        return 0;
    }
    return 1;
}

int area_cilindro(Cilindro c, float *area) {
    if (c != NULL) {
        float altura = c->altura;
        float raio = c->raio;

        float a = 2*PI*raio*(raio+altura); // Fórmula da área total
        *area = a;

        return 0;
    }
    return 1;
}

int volume_cilindro(Cilindro c, float *volume) {
    if (c != NULL) {
        float altura = c->altura;
        float raio = c->raio;

        float v = PI*(raio*raio)*altura;
        *volume = v;

        return 0;
    }
    return 1;

}

void destruir_cilindro(Cilindro c) {
    if (c != NULL)
        free(c);
}
