#include <stdio.h>
#include "quadrado.h"

int main() {
    quadrado q;
    q.l = 10.0;

    printf("Digite o lado do quadrado:\n");
    scanf("%f", &q.l);

    printf("Quadrado com area %.2f e perimetro %.2f\n", calcular_area(q), calcular_perimetro(q));

    return 0;
}
