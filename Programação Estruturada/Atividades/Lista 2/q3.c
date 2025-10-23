#include <stdio.h>
int main() {
  int v[] = {2, 4, 6, 7, 8, 10, 22, 34, 77, 99};
  int target;
  int pos = -1;
  int beg = 0;
  int end = 9;

  printf("Digite um número para pesquisar: \n");
  scanf("%d", &target);

  while (beg <= end) {
    int mid = (beg + end)/2;
    if (v[mid] == target) {
      pos = mid;
      break;
    } else {
      if (v[mid] < target) {
        beg = mid + 1;
      } else {
        end = mid - 1;
      }
    }
  }

  if (pos == -1) {
    printf("Valor não encontrado\n");
  } else {
    printf("Valor encontrado na posição: %d\n", pos);
  }

  return 0;
}
