// Strings = "", char = ''
#include <stdio.h>
int main() {
  char s1[] = "Unicap";      // sem tamanho
  char s2[10] = "Linguagem"; // com o tamanho pra salvar na memória
  // como array (precisa passar elemento de paragem '\0')
  // sem o \0 pode pegar lixo de memória
  // Cada char ocupa 1 byte
  char s3[] = {'G', 'C', 'C', '\0'};

  printf("s1 = %s | tamanho = %d\n", s1, (int)sizeof(s1));
  printf("s2 = %s | tamanho = %d\n", s2, (int)sizeof(s2));
  printf("s3 = %s | tamanho = %d\n", s3, (int)sizeof(s3));
  return 0;
}
