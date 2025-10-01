#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    printf("\nDigite um número maior que 0:\n");
    int valor_lido = -1;
    scanf("%d", &valor_lido);

    if (valor_lido > 0) {
        // Alocando o tamanho lido para o array
        int *v;
        v = (int *)malloc(valor_lido * sizeof(int));

        // Primeiros elementos da sequência de Fibonacci
        v[0] = 0;
        v[1] = 1;
        printf("%d ", v[0]);
        printf("%d ", v[1]);

        // Começando a partir do 3º elemento
        int i = 2;
        do {
            // Evitando lixo de memória
            v[i] = 0;
            // Calculando o próximo
            v[i] = v[i-1] + v[i-2];
            printf("%d ", v[i]);

            i++;
        } while (v[i-1] < valor_lido); // Verificar valor antes do incremento (senão vai pegar lixo de memória)
        free(v);
        v = NULL;
    } else {
        printf("Número inválido. Digite um número maior que 0:\n");
    }

    return 0;
}