#include <stdio.h>
#include <string.h>
void bubble_sort(char s[], int n) {
  int i, j, menor, temp;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (s[j] > s[j+1]) {
        temp = s[j];
        s[j] = s[j+1];
        s[j+1] = temp;
      }
    }
  }
}

int main() {
  char s[51];
  printf("Digite uma frase até 50 caracteres:\n");
  fgets(s, sizeof(s), stdin);
  // Retirando o caractere \n do final
  s[strlen(s)-1] = '\0';
  printf("Frase recebida = '%s'\n", s);

  bubble_sort(s, strlen(s));
  printf("Frase ordenada = '%s'\n", s);

  return 0;
}
