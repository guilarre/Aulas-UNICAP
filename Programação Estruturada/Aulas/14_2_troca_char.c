#include <stdio.h>
void troca_char(char *p1, char *p2) {
  char temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

int main() {
  char a = 'f';
  char b = 'x';

  printf("Antes:\n");
  printf("a = %c | &a = %p\n", a, &a);
  printf("b = %c | &b = %p\n", b, &b);

  troca_char(&a, &b);

  printf("\nDepois:\n");
  printf("a = %c | &a = %p\n", a, &a);
  printf("b = %c | &b = %p\n", b, &b);

  return 0;
}
