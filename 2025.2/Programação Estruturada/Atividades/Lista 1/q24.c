#include <stdio.h>
int main() {
  int X[5];
  int Y[5];
  int produto_escalar = 0;

  printf("Digite números inteiros para o conjunto X:\n");
  for (int i = 0; i < 5; i++) {
    scanf("\n%d", &X[i]);
  }

  printf("\nDigite números inteiros para o conjunto Y:\n");
  for (int i = 0; i < 5; i++) {
    scanf("\n%d", &Y[i]);
  }

  printf("\nConjunto X:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", X[i]);
  }
  printf("\n");

  printf("\nConjunto Y:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", Y[i]);
  }
  printf("\n");

  // Calculando produto escalar
  for (int i = 0; i < 5; i++) {
    produto_escalar += X[i] * Y[i];
  }
  printf("\nProduto escalar = %d\n", produto_escalar);

  return 0;
}
