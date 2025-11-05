#include <stdio.h>
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

  // Duas formas de acessar:
  // Como matriz (multidimensional array)
  for (int i = 0; i < 6; i++) {
    printf("%d ", v[0][i]);
  }
  printf("\n");
  // Desreferenciando os ponteiros
  for (int i = 0; i < 6; i++) {
    printf("%d ", *(*(v)+i));
  }
  return 0;
}
