#include <stdio.h>
#include <locale.h>
int main() {
    // Imprimindo em utf-8
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Criar o array
    int v[10] = {12, 7, 45, 3, 22, 21, 0, 89, 5, 90};
    
    // Variável p/ checagem
    int maior_num = 0;

    // Loop para checagem do maior número
    for (int i = 0; i < 10; i++) {
        int num_atual = v[i];
        if (num_atual > maior_num) {
            maior_num = num_atual;
        }
    }

    // Printando o maior valor
    printf("O maior número do vetor é: %d", maior_num);
}