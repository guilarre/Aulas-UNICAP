#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    char curso[50];
    int idade;
};

typedef struct Aluno aluno;

int main() {
    aluno a1;

    printf("Digite o nome do aluno:\n");
    fgets(a1.nome, 50, stdin);
    a1.nome[strlen(a1.nome) - 1] = '\0';

    printf("Digite o curso:\n");
    fgets(a1.curso, 50, stdin);
    a1.curso[strlen(a1.curso) - 1] = '\0';

    printf("Digite a idade:\n");
    scanf("%d", &a1.idade);

    printf("\nDados lidos:\n\nAluno: %s\nCurso: %s\nIdade: %d", a1.nome, a1.curso, a1.idade);

    return 0;
}
