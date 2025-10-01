#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    unsigned int soma = 0;

    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            soma += i;
        }
    }
    printf("Soma dos números naturais até 1000 que são múltiplos de 3 ou 5: %d", soma);
    return 0;
}