#include <stdio.h>
#include <locale.h> // Pra forçar UTF-8
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Opção pra imprimir em UTF-8
    
    // Variáveis
    float a;
    float b;
    float c;
    
    // Input
    printf("Digite os valores dos 3 lados de um triângulo A, B e C:\n");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    if (a < b + c && b < a + c && c < a + b) {
        if (a == b && b == c) {
            printf("O triângulo é equilátero (três lados iguais).\n");
        } else if (a != b && b != c) {
            printf("O triângulo é escaleno (nenhum lado igual).\n");
        } else {
            printf("O triângulo é isósceles (apenas dois lados iguais).\n");
        }
    } else {
        printf("Os lados informados não podem compor um triângulo\n");
    }
    return 0;
}