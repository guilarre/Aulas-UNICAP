#include <stdio.h>
void selection_sort(int v[], int n) {
  // Algoritmo de seleção direta (O(n^2) pq percorre vetor 2x)
  int i, j, menor, temp;
  for (i = 0; i < n - 1; i++) {
    menor = i; // Troca o início
    for (j = i + 1; j < n; j++) {
      if (v[j] < v[menor]) {
        menor = j;
      }
    }
    // Troca o menor encontrado com o elemento
    // encontrado com o elemento da posição i
    temp = v[i];
    v[i] = v[menor];
    v[menor] = temp;
  }
}

int main() {
  int v[] = {2, 8, 5, 3, 9, 4, 1};
  int n = sizeof(v) / sizeof(int);

  printf("vetor não ordenado: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  // Chamando a função
  selection_sort(v, n);

  printf("vetor ordenado (seleção direta): ");
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;
}
