#include <stdio.h>
#include <string.h>
int main() {
    char frase[100];
    printf("Digite uma frase qualquer:\n");
    fgets(frase, 100, stdin);
    int count = 0;

    for (int i = 0; i < strlen(frase)-1; i++) {
        if (frase[i] == ' ') {
            count++;
        }
    }

    printf("\nQtd de espaços em branco: %d\n", count);

    return 0;
}
