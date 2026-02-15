#include <stdio.h>
unsigned int tamstr(char *s) {
    unsigned int tam;
    unsigned int i = 0;

    while (s[i] != '\0') {
        i++;
    }

    tam = i-1;
    return tam;
}

int main() {
    int n = 50;
    char s[n];

    printf("Digite uma string qualquer:\n");
    fgets(s, n, stdin);
    printf("%c\n", s[n]);
    // n-1 = 49, que é o \0; n-2 = \n que o fgets guarda
    s[n-2] = '\0';

    printf("Tamanho da string: %u\n", tamstr(s));

    return 0;
}
