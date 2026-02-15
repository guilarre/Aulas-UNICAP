#define N 10
#include <stdio.h>
int main() {
  int v_ord[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int v_desord[] = {2, 3, 4, 5, 6, 1, 7, 8, 9, 10};
  int *v = v_desord; // Selecionando o desordenado pra testar

  for (int i = 1; i < N; i++) {
    if (v[i] < v[i-1]) {
      printf("NÃO ORDENADO");
      return 1;
    }
  }
  printf("ORDENADO");

  return 0;
}
