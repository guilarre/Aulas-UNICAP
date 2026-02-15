#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    float salario;
    float prestacao;

    printf("Digite o valor do salário:\n");
    scanf("%f", &salario);
    printf("Digite o valor da prestação:\n");
    scanf("%f", &prestacao);

    if (prestacao > salario*0.2) {
        printf("Empréstimo não concedido\n");
    } else {
        printf("Empréstimo concedido\n");
    }
    return 0;
}