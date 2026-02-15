#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    float valor_premio;
    float valor_investido_A;
    float valor_investido_B;
    float valor_investido_C;
    
    printf("Digite o valor total do prêmio:\n");
    scanf("%f", &valor_premio);
    printf("\nDigite o valor que o apostador A investiu:\n");
    scanf("%f", &valor_investido_A);
    printf("\nDigite o valor que o apostador B investiu:\n");
    scanf("%f", &valor_investido_B);
    printf("\nDigite o valor que o apostador C investiu:\n");
    scanf("%f", &valor_investido_C);

    float investimento_total = valor_investido_A + valor_investido_B + valor_investido_C;
    float A_recebe = (valor_investido_A * valor_premio) / investimento_total;
    float B_recebe = (valor_investido_B * valor_premio) / investimento_total;
    float C_recebe = (valor_investido_C * valor_premio) / investimento_total;

    printf("\nO apostador A deve receber: %.2f\n", A_recebe);
    printf("\nO apostador B deve receber: %.2f\n", B_recebe);
    printf("\nO apostador C deve receber: %.2f\n", C_recebe);

    return 0;
}