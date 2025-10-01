#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    float x;
    int z;
    float resultado = 1;
    
    printf("Vamos calcular uma exponenciação!\n");
    printf("\nDigite um valor para a base:\n");
    scanf("%f", &x);
    printf("Digite um valor inteiro para o expoente:\n");
    scanf("%d", &z);
    
    for (int i = 0; i < z; i++) {
        resultado *= x;
    }

    printf("\nO resultado de %.2f^%d é %.2f.\n", x, z, resultado);
    return 0;
}