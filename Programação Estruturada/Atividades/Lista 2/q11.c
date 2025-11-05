#include <stdio.h>
#include <string.h>
int main() {
  char a[] = "Oi eu sou uma frase";
  char b[] = "123";
  char c[50];
  char space[] = " ";

  strcat(a, space);
  strcat(a, b);
  strcpy(c, a);

  printf("%s\n", c);
}
