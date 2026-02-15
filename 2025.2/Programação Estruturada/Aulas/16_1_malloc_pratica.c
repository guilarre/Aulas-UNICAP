#include <stdio.h>
#include <stdlib.h>
int main() {
  float n;
  float soma;

  printf("Digite o número total de valores do vetor v[]:\n");
  scanf("%f", &n);
  float *v = malloc(n * sizeof(float));

  printf("\nDigite os valores de v[]:\n");
  for (int i = 0; i < n; i++) {
    scanf("%f", (v+i));
  }

  printf("\nv[] = ");
  for (int i = 0; i < n; i++) {
    printf("%.2f ", *(v+i));
    soma += *(v+i);
  }
  printf("\n");

  printf("\nMédia dos valores = %.2f\n", (soma/n));

  free(v);
  return 0;
}
