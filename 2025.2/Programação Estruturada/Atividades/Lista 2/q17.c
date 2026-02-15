#include <stdio.h>
#include <string.h>
int main() {
    char s1[50];
    char s2[50];
    printf("Digite a primeira string:\n");
    fgets(s1, 50, stdin);
    printf("Digite a segunda string:\n");
    fgets(s2, 50, stdin);

    // Tamanho das strings
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len2 > len1) {
        printf("ERRO: A segunda string deve ser menor que a primeira!\n");
        return 1;
    }

    // Ponteiro que recebe primeira pos. do "final" da string 1
    char *final_s1 = &s1[len1-len2];

    // Comparando o final da s1 com s2
    if (strcmp(final_s1, s2) != 0) {
        printf("A segunda string NÃO está contida no final da primeira.\n");
    } else {
        printf("A segunda string está contida no final da primeira.\n");
    }

    return 0;
}
