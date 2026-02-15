#include <stdio.h>
#include <string.h>

int main() {
  char a[40];
  char b[40];
  char menor[40];

  printf("Digite uma palavra: ");
  fgets(a, 40, stdin);
  printf("Digite outra palavra: ");
  fgets(b, 40, stdin);

  int len_a = (int)strlen(a);
  int len_b = (int)strlen(b);
  if (len_a < len_b) {
    strcpy(menor, a);
  }

  printf("Menor palavra: %s", menor);
  printf("\n"); // caso o tamanho da string não permita inserção do \n pelo fgets()
  return 0;
}
