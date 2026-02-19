#include <stdio.h>
#include "circulo.h"

int main() {
    // Criando o círculo com o raio passado pelo user
    float r;
    printf("Digite o raio do círculo: ");
    scanf("%f", &r);
    Circulo c = cria_circulo(r);

    printf("Círculo de raio %.2f, com área %.2f e perímetro %.2f\n",
    acessa_raio(c), calcula_area(c), calcula_perimetro(c));
 
    destroi_circulo(c);
    return 0;
}
