#include <stdio.h>
#include <string.h>
#define N 5
void selection_sort(char **v) {
  int i, j, menor;
  char *temp;
  for (i = 0; i < N-1; i++) {
    menor = i;
    for (j = i+1; j < N; j++) {
      if (strlen(v[j]) < strlen(v[menor])) {
        menor = j;
      }
    }
    temp = v[i];
    v[i] = v[menor];
    v[menor] = temp;
  }
}

int main() {
  char nome_1[] = "Guilherme";
  char nome_2[] = "Carlos";
  char nome_3[] = "Alexandre da Silva Sauro";
  char nome_4[] = "Duda";
  char nome_5[] = "Mayara";

  char *v[] = {nome_1, nome_2, nome_3, nome_4, nome_5};

  printf("Nomes em v[]: ");
  for (int i = 0; i < N; i++) {
    printf("%s ", v[i]);
  }
  printf("\n");

  selection_sort(v);

  printf("Nomes ordenados por tamanho: ");
  for (int i = 0; i < N; i++) {
    printf("%s ", v[i]);
  }
  printf("\n");

  return 0;
}
