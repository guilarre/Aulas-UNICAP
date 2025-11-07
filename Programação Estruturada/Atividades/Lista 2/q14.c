#include <string.h>
#include <stdio.h>
int main() {
    char s[50];

    printf("Digite uma palavra:\n");
    fgets(s, 50, stdin);

    int n = strlen(s);
    s[n-1] = '\0';

    for (int i = n-2; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}
