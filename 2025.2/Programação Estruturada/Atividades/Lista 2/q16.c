#include <stdio.h>
#include <string.h>
int main() {
    char s1[] = "arara";
    char s2[] = "hannah";
    char s3[] = "guilherme";
    char string_escolhida[50], string_invertida[50];

    // Escolhendo a string para testar
    strcpy(string_escolhida, s1);
    int n = strlen(string_escolhida);

    // Invertendo as strings
    for (int i = 0; i < n ; i++) {
        int j = n-1-i;
        string_invertida[i] = string_escolhida[j];
    }

    // Comparando (se 0 são iguais)
    if (strcmp(string_invertida, string_escolhida) != 0) {
        printf("A string '%s' não é palíndromo", string_escolhida);
    } else {
        printf("A string '%s' é palíndromo", string_escolhida);
    }

    printf("\n");

    return 0;
}
