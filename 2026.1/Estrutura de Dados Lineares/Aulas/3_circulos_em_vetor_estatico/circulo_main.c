#include <stdio.h>
#include "circulo.h"

int main() {
    // Criando vetor com 5 círculos
    Circulo *vc = criar_vetor_circulos();

    // Chamando funções para cada círculo
    for (int i = 0; i < N; i++) {
        printf("Círculo de raio %.2f, com área %.2f e perímetro %.2f\n", acessa_raio(vc[i]), calcula_area(vc[i]), calcula_perimetro(vc[i]));
    }

    // Chamando funções de comparação
    maior_area(vc);
    menor_area(vc);
    maior_perimetro(vc);
    maior_perimetro(vc);

    // Destruindo tudo
    for (int i = 0; i < N; i++) {
        destroi_circulo(vc[i]);
    }

    return 0;
}
