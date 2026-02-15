#include <stdio.h>
#include <stdlib.h>
int main() {
    int tam; // Tamanho da string s
    int tam_bytes; // Tamanho em bytes
    char *s = NULL;

    printf("Digite o tamanho desejado para uma string:\n");
    scanf("%d", &tam);
    getchar(); // Tirando o \n
    tam_bytes = tam * sizeof(int);

    // Alocando tamanho dinamicamente
    s = malloc(tam_bytes);

    printf("\nDigite o conteúdo da string:\n");
    fgets(s, tam_bytes, stdin);

    printf("\nA string sem suas vogais é:\n");

    for (int i = 0; i < tam_bytes; i++) {
        if (s[i] != 'a' && s[i] != 'A' && s[i] != 'e' && s[i] != 'E' && s[i] != 'i' && s[i] != 'I' && s[i] != 'o' && s[i] != 'O' && s[i] != 'u' && s[i] != 'U') {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    return 0;
}
