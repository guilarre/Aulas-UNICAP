#include <stdio.h>
#include <locale.h> // Pra forçar UTF-8

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Opção pra imprimir em UTF-8

    float peso;
    float altura;
    float imc;

    printf("Digite seu peso (kg), e.g. 80: ");
    scanf("%f", &peso);

    printf("Digite sua altura (m), e.g. 1.75: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);
    printf("Seu IMC é: %.2f\n", imc);

    // Mensagem extra sobre imc
    if (imc < 22) {
        printf("Você tem baixo peso\n");
    }
    else if (22 >= imc > 27) {
        printf("Você tem peso normal\n");
    }
    else if (27 >= imc > 30) {
        printf("Você tem sobrepeso\n");
    }
    else {
        printf("Você está em obesidade\n");
    }
    return 0;
}