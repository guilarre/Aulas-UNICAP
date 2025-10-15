#include <stdio.h>
int main() {
  int v[] = {2, 8, 5, 3, 9, 4, 1};
  int n = sizeof(v) / sizeof(v[0]);
  int i, j, temp;

  printf("Vetor original: ");
  for (i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  for (i = 0; i < n - 1; i++) {
    // até (j < n-i-1) pq compara os índ. j com j+1
    for (j = 0; j < n - i - 1; j++) {
      // Compara os pares, e se for maior vai trocar
      if (v[j] > v[j + 1]) {
        temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }

  printf("Vetor ordenado (bolha): ");
  for (i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;
}
