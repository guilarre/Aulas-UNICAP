#include <stdio.h>
int conta_maiores(int *v, int n, int valor) {
    int maiores = 0;

    for (int i = 0; i < n; i++) {
        if (*(v+i) > valor) {
            maiores++;
        }
    }

    return maiores;
}

int main() {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(v)/sizeof(v[0]);
    int valor;

    printf("Digite um valor para comparação:\n");
    scanf("%d", &valor);

    int maiores = conta_maiores(v, n, valor);

    printf("%d valores são maiores do que o valor informado.\n", maiores);

    return 0;
}
