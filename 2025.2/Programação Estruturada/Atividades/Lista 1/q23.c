#include <stdio.h>
#define N 10
int main() {
  int v[N];
  int menor, maior;

  printf("Digite 10 valores para o vetor v:\n");
  for (int i = 0; i < N; i++) {
    scanf("%d", &v[i]);
  }

  // Printando o vetor lido
  printf("Vetor lido:\n");
  for (int i = 0; i < N; i++) {
    printf("v[%d] = %d\n", i, v[i]);
  }

  // Maior valor
  maior = v[0];
  for (int i = 1; i < N; i++) {
    if (v[i] > maior) {
      maior = v[i];
    }
  }
  printf("\nMaior valor: %d\n", maior);

  // Menor valor
  menor = v[0];
  for (int i = 1; i < N; i++) {
    if (v[i] < menor) {
      menor = v[i];
    }
  }
  printf("Menor valor: %d\n", menor);

  return 0;
}
