#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    float r1 = 0;
    float r2 = 0;

    printf("\nVamos calcular o valor da resistência equivalente de 2 resistores em paralelo!\n");
    printf("(Digite 0 se desejar sair)\n");

    while (1) {
        printf("\nDigite o valor de R1:\n");
        scanf("%f", &r1);
        if (r1 == 0) {
            break;
        }
        printf("Digite o valor de R2:\n");
        scanf("%f", &r2);
        if (r2 == 0) {
            break;
        }

        float r_eq = (r1*r2)/(r1+r2);
        printf("\nA resistência equivalente é igual a %.2fΩ\n", r_eq);
    }

    return 0;
}