#include <stdio.h>
#include <string.h>
int main() {
  char a[] = "oi eu sou a frase A";
  char b[] = "e eu sou a frase B";
  
  if (strcmp(a, b) > 0) {
    printf("A frase A vem primeiro");
  } else if (strcmp(a, b) < 0) {
    printf("A frase B vem primeiro");
  } else if (strcmp(a, b) == 0) {
    printf("As frases vem na mesma ordem");
  }

  printf("%d", strcmp(a, b) > 0);
  return 0;
}
