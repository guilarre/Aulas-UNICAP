#include <stdio.h>

int main() {
  int v[] = {2, 8, 5, 3, 9, 4, 1};
  int n = sizeof(v) / sizeof(v[0]);
  int i, j, menor, temp;

  printf("Ordenando (selection)...\n\n");
  for (i = 0; i < n - 1; i++) {
    menor = i;
    for (j = i + 1; j < n; j++) {
      if (v[j] < v[menor]) {
        menor = j;
      }
    }

    // Checando vetor a cada alteração
    for (int k = 0; k < n; k++) {
      printf("%d ", v[k]);
    }
    printf("\n");

    temp = v[i];
    v[i] = v[menor];
    v[menor] = temp;
  }

  printf("\nVetor ordenado (Selecao Direta): ");
  for (i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;
}

// Output mostra estado do vetor ao final
// de cada iteração do selection sort:
// 
// i = 0: começa selecionando o 2 (1º elem.) como MENOR e compara com o resto do array
// 2 8 5 3 9 4 1 -> encontra MENOR (2) < j e troca posições
// 1 8 5 3 9 4 2 -> i = 1: MENOR é alterado p 8 e compara com o resto do array à direita
// 1 2 5 3 9 4 8 -> assim por diante
// 1 2 3 5 9 4 8
// 1 2 3 4 9 5 8
// 1 2 3 4 5 9 8
