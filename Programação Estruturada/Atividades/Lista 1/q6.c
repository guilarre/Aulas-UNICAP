#include <stdio.h>
int main() {
    float h;
    float r;
    float pi = 3.141592;
    float v;

    // Lendo do input
    printf("Vamos calcular o volume de um cilindro.\n");
    printf("Digite o valor da altura do cilindro:\n");
    scanf("%f", &h);
    printf("Digite o valor do raio do cilindro:\n");
    scanf("%f", &r);

    // Calculando o volume
    v = pi*(r*r)*h;
    printf("O cilindro tem volume: %.2f u.v.\n", v);

    return 0;
}