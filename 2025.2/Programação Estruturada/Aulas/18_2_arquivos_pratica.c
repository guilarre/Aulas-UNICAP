// Atividade
// Crie um programa que leia de um arquivo numeros.txt uma lista de inteiros, 
// calcule a média e grave em um novo arquivo media.txt a média e a quantidade de valores lidos.

#include <stdio.h>
int main() {
    FILE *fp_num = fopen("numeros.txt", "r");
    FILE *fp_media = fopen("media.txt", "w");
    if (fp_num == NULL || fp_media == NULL) {
        printf("Erro ao abrir o arquivo!");
        if (fp_num) {
            fclose(fp_num);
        }
        if (fp_media) {
            fclose(fp_media);
        }
        return 1;
    }

    int media = 0;
    int soma = 0;
    int n = 0;
    int buf = 0;
    while (fscanf(fp_num, "%d", &buf) != EOF) {
        soma += buf;
        n++;
    }

    if (n != 0) {
        media = soma/n;
        fprintf(fp_media, "%d\n", media);
    } else {
        printf("Erro ao ler o arquivo!");
    }

    fclose(fp_num);
    fclose(fp_media);

    return 0;
}
