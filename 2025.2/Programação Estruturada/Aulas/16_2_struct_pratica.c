// Atividade
// Crie uma struct chamada "Aluno" com os campos:
// nome, curso e idade.
// Leia os dados de um aluno e imprima.
#include <stdio.h>
#include <string.h>
struct Aluno {
  char nome[50];
  char curso[50];
  int idade;
};

int main() {
  struct Aluno a1;

  printf("# Digite o nome do aluno:\n");
  fgets(a1.nome, sizeof(a1.nome), stdin); //pode usar strlen tb se já tiver valor inicializado
  printf("# Digite o curso do aluno:\n");
  fgets(a1.curso, sizeof(a1.curso), stdin);
  printf("# Digite a idade do aluno:\n");
  scanf("%d", &a1.idade);

  // Tirando o \n do fgets
  a1.nome[strlen(a1.nome) - 1] = '\0';
  a1.curso[strlen(a1.curso) - 1] = '\0';

  printf("\n## Dados do aluno ##\n");
  printf("Nome: %s\n", a1.nome);
  printf("Curso: %s\n", a1.curso);
  printf("Idade: %d\n", a1.idade);

  return 0;
}
