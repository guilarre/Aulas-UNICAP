#include <stdio.h>
int main() {
  char s[] = "Pernambuco";
  printf("Antes: %s\n", s);
  s[5] = '\0';
  printf("Depois: %s\n", s);

  return 0;
}
