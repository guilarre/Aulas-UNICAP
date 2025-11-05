#include <stdio.h>
int main() {
  char s[] = "Guilherme Raposo G. de M. Larré";
  printf("Nome digitado: %s\n", s);
  printf("Endereço na memória: %p\n", &s);

  return 0;
}
