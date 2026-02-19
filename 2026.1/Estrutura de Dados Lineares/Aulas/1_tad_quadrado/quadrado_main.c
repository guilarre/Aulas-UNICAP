#include<stdio.h>
#include"quadrado.h"

int main(){
    float lado;
    
    printf("Insira o lado do quadrado: ");
    scanf("%f", &lado);
    
    Quadrado q = cria_quadrado(lado);

    printf("Quadrado de lado %.2f, com area %.2f e perimetro %.2f\n",
        acessa_lado(q), calculo_area(q), calculo_perimetro(q));

    // vai dar erro:
    /*
    printf("Quadrado de lado %.2f, com area %.2f e perimetro %.2f\n",
        q.l, q.l*q.l, 4*q.l);
    */

    destruir_quadrado(q);
    return 0;
}