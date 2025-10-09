#include <stdio.h>
// Função para transformar a matriz
int transformar_matriz(int M[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i != j && j > i) {
        M[i][j] = 0;
      }
    }
  }

  return 0;
}

int main() {
  int M[4][4];
  int count = 1;

  // Inicializando a matriz com valores a partir de 1
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      M[i][j] = count;
      count++;
    }
  }

  // Printando a matriz original
  printf("Matriz original:\n\n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }

  // Transformando a matriz
  transformar_matriz(M);

  printf("\nMatriz nova:\n\n");
  // Printando a matriz nova
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }

  return 0;
}
