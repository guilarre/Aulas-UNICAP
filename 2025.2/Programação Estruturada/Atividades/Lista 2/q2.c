#include <stdio.h>
int main() {
  int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target;
  int pos = -1;

  printf("Digite um número para pesquisar: \n");
  scanf("%d", &target);

  for (int i = 0; i < 10; i++) {
    if (v[i] == target) {
      pos = i;
      break;
    }
  }

  if (pos == -1) {
    printf("Valor não encontrado\n");
  } else {
    printf("Valor encontrado na posição: %d\n", pos);
  }

  return 0;
}
