#include <stdio.h>

void triangulo(int n) {
    for (int i = 1; i <= n; i++) {
        // Espaços
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Asteriscos
        for (int j = 1; j <= 2*i-1; j++) {
            printf("*");
        }
        printf("\n");
    }
}
int main() {
    int n = 6;
    triangulo(n);
    return 0;
}