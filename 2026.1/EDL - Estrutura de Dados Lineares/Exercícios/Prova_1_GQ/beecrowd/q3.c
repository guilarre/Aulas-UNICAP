#include <stdio.h>
#include <string.h>
int main() {
    // string com até 1000 caracteres
    char s[1000];

    while (fgets(s, 1000, stdin) != NULL) {
        int opening_p = 0;
        int closing_p = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '(')
                opening_p++;
            else if (s[i] == ')')
                closing_p++;
                if (closing_p > opening_p)
                    break;
        }
        if (opening_p == closing_p)
            printf("correct\n");
        else
            printf("incorrect\n");
    }
    return 0;
}
