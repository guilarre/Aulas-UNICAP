#include <stdio.h>
#include <string.h>
void selection_sort(int v_origin[], int n) {
  // Criando cópia pra não afetar counts
  int v[n];
  memcpy(v, v_origin, n*sizeof(int));

  int i, j, menor, temp;
  int count_comp = 0, count_troca = 0;
  for (i = 0; i < n-1; i++) {
    menor = i;
    for (j = i+1; j < n; j++) {
      count_comp++;
      if (v[j] < v[menor]) {
        menor = j;
      }
    }
    count_troca++;
    temp = v[i];
    v[i] = v[menor];
    v[menor] = temp;
  }
  printf("O selection sort realizou %d comparações e %d trocas\n", count_comp, count_troca);
}

void bubble_sort(int v_origin[], int n) {
  // Criando cópia pra não afetar counts
  int v[n];
  memcpy(v, v_origin, n*sizeof(int));

  int i, j, menor, temp;
  int count_comp = 0, count_troca = 0;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      count_comp++;
      if (v[j] > v[j+1]) {
        count_troca++;
        temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;
      }
    }
  }
  printf("O bubble sort realizou %d comparações e %d trocas\n", count_comp, count_troca);
}

// Esse não copia o vetor antes, pra poder printar o vetor ordenado na main
void insertion_sort(int v[], int n) {
  int i, j, key;
  int count_comp = 0, count_troca = 0;
  for (j = 1; j < n; j++) {
    key = v[j];
    i = j-1;
    while (i >= 0) {
      count_comp++;
      if (v[i] > key) {
        v[i+1] = v[i];
        count_troca++;
        i--;
      } else {
        break;
      }
    }
    v[i+1] = key;
  }
  printf("O insertion sort realizou %d comparações e %d trocas\n", count_comp, count_troca);
}

int main() {
  int v0[] = {2, 4, 6, 8, 10, 12};
  int v1[] = {11, 9, 7, 5, 3, 1};
  int v2[] = {5, 7, 2, 8, 1, 6};
  int v3[] = {2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1};
  int v4[] = {2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11};
  int v5[] = {8, 9, 7, 9, 3, 2, 3, 8, 4, 6};
  int v6[] = {89, 79, 32, 38, 46, 26, 43, 38, 32, 79};
  // Array contendo os outros arrays (ponteiro de ponteiro)
  int *v[] = {v0, v1, v2, v3, v4, v5, v6};
  // Tamanhos
  int sizes[] = {
    sizeof(v0) / sizeof(v0[0]),
    sizeof(v1) / sizeof(v1[0]),
    sizeof(v2) / sizeof(v2[0]),
    sizeof(v3) / sizeof(v3[0]),
    sizeof(v4) / sizeof(v4[0]),
    sizeof(v5) / sizeof(v5[0]),
    sizeof(v6) / sizeof(v6[0])
  };

  for (int i = 0; i < 7; i++) {
    int n = sizes[i];

    printf("\n## Vetor %d ##\n", i+1);
    printf("Vetor inicial: ");
    for (int j = 0; j < n; j++) {
      printf("%d ", v[i][j]);
    }
    printf("\n");

    selection_sort(v[i], n);
    bubble_sort(v[i], n);
    insertion_sort(v[i], n); // Modifica o vetor

    printf("Vetor ordenado: ");
    for (int j = 0; j < n; j++) {
      printf("%d ", v[i][j]);
    }
    printf("\n");
  }

  return 0;
}
