#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    char str[3];

    printf("Digite um número inteiro positivo de três dígitos:\n");
    scanf("%s", &str);

    printf("\nNúmero lido = %s\n", str);

    printf("Número gerado = ");
    for (int i = 2; i >= 0; i--) {
        printf("%c", str[i]);
    }
    
    printf("\n");
    return 0;
}