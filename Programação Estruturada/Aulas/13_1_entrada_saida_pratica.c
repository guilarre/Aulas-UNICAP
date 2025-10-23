#include <stdio.h>
int main() {
  char nome[40];

  // Recebendo do terminal
  fputs("Digite o nome completo: ", stdout);
  fgets(nome, 40, stdin);

  // Printando em tela o nome completo
  fputs("\nNome completo:\n", stdout);
  fputs(nome, stdout);

  // Printando em tela o endereço do priemiro elemento
  printf("Endereço de nome[0] = %p\n", &nome[0]);

  return 0;
}
