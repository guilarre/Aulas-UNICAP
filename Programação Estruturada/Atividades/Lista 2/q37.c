#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int matricula;
    char curso[50];
};

int main() {
    struct Aluno v_alunos[5];

    for (int i = 0; i < 5; i++) {
        printf("\nDigite o nome do aluno #%d:\n", i+1);
        fgets(v_alunos[i].nome, 50, stdin);
        v_alunos[i].nome[strlen(v_alunos[i].nome) - 1] = '\0';

        printf("Digite a matrícula:\n");
        scanf("%d", &v_alunos[i].matricula);
        getchar();

        printf("Digite o nome do curso:\n");
        fgets(v_alunos[i].curso, 50, stdin);
        v_alunos[i].curso[strlen(v_alunos[i].curso) - 1] = '\0';
    }

    printf("\n#### Alunos registrados com sucesso ####\n");
    for (int i = 0; i < 5; i++) {
        printf("\nAluno #%d:\n" \
               "\nNome: %s\n" \
               "Matrícula: %d\n" \
               "Curso: %s\n",
               i+1, v_alunos[i].nome, v_alunos[i].matricula, v_alunos[i].curso);
    }

    return 0;
}
