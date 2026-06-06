#include "q4.h"

int main() {
    Complexo c1 = criar_complexo(2, 3);
    Complexo c2 = criar_complexo(1, 4);

    Complexo c3 = somar_complexos(c1, c2);
    printf("1. Soma:\n");
    printa_complexo(c3);
    printf("\n");

    c3 = subtrair_complexos(c1, c2);
    printf("2. Subtração:\n");
    printa_complexo(c3);
    printf("\n");

    c3 = multiplicar_complexos(c1, c2);
    printf("3. Multiplicação:\n");
    printa_complexo(c3);
    printf("\n");

    c3 = dividir_complexos(c1, c2);
    printf("4. Divisão:\n");
    printa_complexo(c3);
    printf("\n");

    return 0;
}
