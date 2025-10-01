#include <stdio.h>
// Definir a função fora
float serie(int N) {
    float somatorio = 0;
    for (int i = 1; i <= N; i++) {
        somatorio += ((i*i)+1)/(float)(i+3); // Precisa dar o cast p/ float, pois i é int
    }
    return somatorio;
}
// Chamar a função com o valor de N
int main() {
    int N = 10;
    float somatorio = serie(N);

    printf("%.2f\n", somatorio);
    return 0;
}