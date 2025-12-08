#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[100];
    int matricula, codigo_disciplina;
    // Média ponderada: nota1 peso 1, nota2 peso 2
    float nota1, nota2, media_ponderada;
};

typedef struct Aluno aluno;

int main() {
    // TODO: trocar n pra 10
    int n = 3;
    aluno alunos[n];

    for (int i = 0; i < n; i++) {
        printf("\n####### Registro do aluno #%d #######\n", i+1);
        printf("\nDigite o número da matrícula:\n");
        scanf("%d", &alunos[i].matricula);
        getchar(); // Retirando o '\n' do buffer antes do fgets

        printf("Digite o nome:\n");
        fgets(alunos[i].nome, 100, stdin);
        // Retirando o '\n' do fgets
        alunos[i].nome[strlen(alunos[i].nome) - 1] = '\0';

        printf("Digite o código da disciplina:\n");
        scanf("%d", &alunos[i].codigo_disciplina);

        printf("Digite a primeira nota:\n");
        scanf("%f", &alunos[i].nota1);

        printf("Digite a segunda nota:\n");
        scanf("%f", &alunos[i].nota2);

        alunos[i].media_ponderada = (alunos[i].nota1 * 1 + alunos[i].nota2 * 2) / 3;
    }

    // Output final
    for (int i = 0; i < n; i++) {
        printf("\n####### Aluno #%d #######\n", i+1);
        printf("\nMatrícula:%d\n", alunos[i].matricula);
        printf("Nome:%s\n", alunos[i].nome);
        printf("Código da disciplina:%d\n", alunos[i].codigo_disciplina);
        printf("Nota 1:%.2f\n", alunos[i].nota1);
        printf("Nota 2:%.2f\n", alunos[i].nota2);
        printf("Média ponderada:%.2f\n", alunos[i].media_ponderada);
    }

    printf("\n");

    return 0;
}
