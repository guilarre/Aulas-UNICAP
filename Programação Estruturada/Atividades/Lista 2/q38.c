#include <stdio.h>
#include <string.h>
#define N 100

struct Aluno {
    int matricula;
    char nome[N];
    float nota1, nota2, nota3, media;
    int aprovado; // 0 = reprovado, 1 = aprovado
};

typedef struct Aluno aluno;

int main() {
    int n = 5; // Qtd desejada de alunos
    aluno alunos[n];

    for (int i = 0; i < n; i++) {
        // Soma pra calcular média
        float soma = 0;

        printf("########### Aluno %d ############\n\n", i+1);
        printf("Digite o número de matrícula:\n");
        scanf("%d", &alunos[i].matricula);
        getchar(); // Tirando \n do buffer antes do fgets

        printf("\nDigite o nome do aluno:\n");
        fgets(alunos[i].nome, N, stdin);
        alunos[i].nome[strlen(alunos[i].nome) - 1] = '\0';

        printf("\nDigite a nota da primeira prova:\n");
        scanf("%f", &alunos[i].nota1);
        printf("\nDigite a nota da segunda prova:\n");
        scanf("%f", &alunos[i].nota2);
        printf("\nDigite a nota da terceira prova:\n");
        scanf("%f", &alunos[i].nota3);

        // Calculando a média
        soma += alunos[i].nota1;
        soma += alunos[i].nota2;
        soma += alunos[i].nota3;
        alunos[i].media = soma / 3;
    }

    aluno aluno_maior_nota1 = alunos[0]; // Maior primeira nota
    aluno aluno_maior_media = alunos[0];
    aluno aluno_menor_media = alunos[0];

    for (int i = 0; i < n; i++) {
        // Requisitos
        // b) Aluno com a maior nota na primeira prova
        if (alunos[i].nota1 > aluno_maior_nota1.nota1) {
            aluno_maior_nota1 = alunos[i];
        }

        // c) Aluno com maior média
        if (alunos[i].media > aluno_maior_media.media) {
            aluno_maior_media = alunos[i];
        }

        // d) Aluno com menor média
        if (alunos[i].media < aluno_menor_media.media) {
            aluno_menor_media = alunos[i];
        }

        // e) Dizer se foi aprovado ou não (média 6)
        if (alunos[i].media >= 6) {
            alunos[i].aprovado = 1; // 1 = True
        } else {
            alunos[i].aprovado = 0; // 0 = False
        }
    }

    // Output final
    // b)
    printf("\nO aluno com a maior nota na primeira prova foi %s, com nota %.2f\n", aluno_maior_nota1.nome, aluno_maior_nota1.nota1);

    // c)
    printf("O aluno com a maior média geral foi %s, com média %.2f\n", aluno_maior_media.nome, aluno_maior_media.media);

    // d)
    printf("O aluno com a menor média geral foi %s, com média %.2f\n", aluno_menor_media.nome, aluno_menor_media.media);

    // e)
    for (int i = 0; i < n; i++) {
        if (alunos[i].aprovado == 1) {
            printf("\nO aluno %s está aprovado! :D", alunos[i].nome);
        } else {
            printf("\nO aluno %s está reprovado! :'(", alunos[i].nome);
        }
    }
    printf("\n");

    return 0;
}
