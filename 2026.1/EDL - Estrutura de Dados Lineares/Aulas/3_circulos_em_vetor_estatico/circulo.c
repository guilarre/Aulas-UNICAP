#include <stdlib.h>
#include <stdio.h>
#include "circulo.h"

struct Circulo_st {
    float r;
};

Circulo cria_circulo(float r) {
    if (r < 0)
        r *= -1;

    Circulo c = malloc(sizeof(struct Circulo_st));
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
    return PI * (c->r * c->r);
}

float calcula_perimetro(Circulo c) {
    return 2 * PI * c->r;
}

// Função nova pra criar 5 círculos em vetor e retornar vetor
Circulo *criar_vetor_circulos() {
    // Vetor estático pra guardar os círculos
    // Com malloc, guardamos na HEAP. Com o v[], guardamos
    // na STACK
    Circulo *vetor_circulos = malloc(N * sizeof(Circulo));
    for (int i = 0; i < N; i++) {
        float r;
        printf("Digite o raio do círculo: ");
        scanf("%f", &r);
        vetor_circulos[i] = cria_circulo(r);
        printf("Círculo #%d armazenado com sucesso!\n", i+1);
    }
    return vetor_circulos;
}

// Funções de comparação entre círculos
void maior_area(Circulo *vetor_circulos) {
    int i;
    Circulo c_maior_area = vetor_circulos[0];
    for (i = 1; i < N; i++) {
        if (calcula_area(vetor_circulos[i]) > calcula_area(c_maior_area)) {
            c_maior_area = vetor_circulos[i];
        }
    }
    printf("O círculo de maior área é o círculo #%d, com área %.2f\n", i, calcula_area(c_maior_area));
}

void menor_area(Circulo *vetor_circulos) {
    int i;
    Circulo c_menor_area = vetor_circulos[0];
    for (i = 1; i < N; i++) {
        if (calcula_area(vetor_circulos[i]) < calcula_area(c_menor_area)) {
            c_menor_area = vetor_circulos[i];
        }
    }
    printf("O círculo de menor área é o círculo #%d, com área %.2f\n", i, calcula_area(c_menor_area));
}

void maior_perimetro(Circulo *vetor_circulos) {int i;
    Circulo c_maior_perimetro = vetor_circulos[0];
    for (i = 1; i < N; i++) {
        if (calcula_perimetro(vetor_circulos[i]) > calcula_perimetro(c_maior_perimetro)) {
            c_maior_perimetro = vetor_circulos[i];
        }
    }
    printf("O círculo de maior perímetro é o círculo #%d, com perímetro %.2f\n", i, calcula_perimetro(c_maior_perimetro));
}

void menor_perimetro(Circulo *vetor_circulos) {
    int i;
    Circulo c_menor_perimetro = vetor_circulos[0];
    for (i = 1; i < N; i++) {
        if (calcula_perimetro(vetor_circulos[i]) < calcula_perimetro(c_menor_perimetro)) {
            c_menor_perimetro = vetor_circulos[i];
        }
    }
    printf("O círculo de menor perímetro é o círculo #%d, com perímetro %.2f\n", i, calcula_perimetro(c_menor_perimetro));
}

void destroi_vetor(Circulo *vetor_circulos) {
    free(vetor_circulos);
}
