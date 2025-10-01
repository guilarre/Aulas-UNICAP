#include <stdio.h>
int main() {
    int n;
    int num_atual = 0;

    printf("Digite um numero inteiro positivo:\n");
    scanf("%d", &n);
    printf("\n");
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            num_atual += 1;
            printf("%d ", num_atual);
        }
        printf("\n");
    }
    return 0;
}