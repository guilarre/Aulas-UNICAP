#include <stdio.h>
#include <stdlib.h>
#define N 30
int retornar_pares_impares(int X[N], int *A, int *B) {
  int i_pares = 0;
  int i_impares = 0;

  for (int i = 0; i < N; i++) {
    if (X[i] % 2 == 0) {
      *(A + i_pares) = X[i];
      i_pares++;
    } else {
      *(B + i_impares) = X[i];
      i_impares++;
    }
  }

  return 0;
}

int main() {
  int X[N];

  // Colocando alguns números em X
  int num = 5;
  for (int i = 0; i < N; i++) {
    X[i] = num;
    num += 5;
  }

  // Printando elementos de X
  printf("X (todos): ");
  for (int i = 0; i < N; i++) {
    printf("%d ", X[i]);
  }
  printf("\n");

  // Contando números pares e ímpares
  // Pares
  int count_pares = 0;
  for (int i = 0; i < N; i++) {
    if (X[i] % 2 == 0) {
      count_pares++;
    }
  }
  // Ímpares
  int count_impares = 0;
  for (int i = 0; i < N; i++) {
    if (X[i] % 2 != 0) {
      count_impares++;
    }
  }

  // Criando arrays A e B
  // Ponteiro A, recebe tamanho de a referente ao nº de pares
  int *A = (int *)malloc(sizeof(int) * count_pares);
  // Ponteiro B, recebe tamanho de a referente ao nº de ímpares
  int *B = (int *)malloc(sizeof(int) * count_impares);

  // Chamando a função criada
  retornar_pares_impares(X, A, B);

  // Printando A e B
  printf("A (pares): ");
  for (int i = 0; i < count_pares; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");

  printf("B (impares): ");
  for (int i = 0; i < count_impares; i++) {
    printf("%d ", B[i]);
  }
  printf("\n");

  // Liberando o espaço na memória
  free(A);
  free(B);
  return 0;
}
