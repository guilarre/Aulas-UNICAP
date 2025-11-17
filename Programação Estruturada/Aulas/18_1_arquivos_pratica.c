// Atividade
// Crie um programa que grave duas linhas em um arquivo de texto
// chamado "saida.txt".
// A primeira linha deve conter o seu nome e a segunda o nome do curso.
// Depois leia o conteúdo do arquivo e mostre no terminal

#include <stdio.h>
int main() {
    // Escrevendo no arquivo
    FILE *fp = fopen("saida.txt", "w");

    if (fp == NULL) {
        printf("Erro ao abrir arquivo!");
        if (fp) {
            fclose(fp);
        }
        return 1;
    }

    char nome[] = "Guilherme";
    char curso[] = "Ciência da Computação";
    fprintf(fp, "%s\n%s", nome, curso);

    fclose(fp);

    // Lendo o arquivo
    fp = fopen("saida.txt", "r");

    if (fp == NULL) {
        printf("Erro ao abrir arquivo!");
        if (fp) {
            fclose(fp);
        }
        return 1;
    }

    char buf[50];
    // O fgets recebe uma linha inteira, o fscanf recebe por palavra
    while (fgets(buf, 50, fp) != NULL) {
        printf("%s", buf);
    }
    printf("\n");
    fclose(fp);

    return 0;
}
