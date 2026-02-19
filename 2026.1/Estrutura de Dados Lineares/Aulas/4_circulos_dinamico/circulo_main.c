#include <stdio.h>
#include "circulo.h"

int main() {
    // Prompt pro tamanho do vetor
    int n = 0;
    printf("Quantos círculos deseja criar? ");
    scanf("%d", &n);
    printf("\n");

    Circulo *vc = criar_vetor_circulos(n);

    // Chamando funções para cada círculo
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Círculo de raio %.2f, com área %.2f e perímetro %.2f\n", acessa_raio(vc[i]), calcula_area(vc[i]), calcula_perimetro(vc[i]));
    }

    // Chamando funções de comparação
    printf("\n");
    maior_area(vc, n);
    menor_area(vc, n);
    maior_perimetro(vc, n);
    maior_perimetro(vc, n);

    // Destruindo tudo
    // Círculos
    for (int i = 0; i < n; i++) {
        destroi_circulo(vc[i]);
    }
    // Vetor
    destroi_vetor(vc);

    return 0;
}
