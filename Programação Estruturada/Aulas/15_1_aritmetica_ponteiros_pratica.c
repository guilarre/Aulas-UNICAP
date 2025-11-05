#include <stdio.h>
void incrementa_pares(int *v, int n) {
  for (int i = 0; i < n; i++) {
    if (*(v+i) % 2 == 0) {
      *(v+i) += 1;
    }
  }
}

int main() {
  int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = 10;

  printf("Vetor antes: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", *(v+i));
  }
  printf("\n");

  // Chamando a função
  incrementa_pares(v, n);
  printf("Vetor depois: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", *(v+i));
  }
  printf("\n");

  return 0;
}
