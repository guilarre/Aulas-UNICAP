#include <stdio.h>
int main() {
  int v[] = {2, 8, 5, 3, 9, 4, 1};
  int n = sizeof(v) / sizeof(v[0]);
  int i, j, key;

  printf("Ordenando (insertion)...\n");
  for (j = 1; j < n; j++) {
    key = v[j];
    i = j - 1;
    while (i >= 0 && v[i] > key) {
      printf("Entrou no while, i = %d, v[i] = %d, key = %d", i, v[i], key);
      printf(" -> v[%d] = %d\n", i+1, v[i]);
      v[i + 1] = v[i];
      i--;
    }
    v[i + 1] = key;

    for (int k = 0; k < n; k++) {
      printf("%d ", v[k]);
    }
    printf("\n");
  }

  // Impressão do vetor ordenado
  printf("Vetor ordenado (Insercao Direta): ");
  for (i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;
}
