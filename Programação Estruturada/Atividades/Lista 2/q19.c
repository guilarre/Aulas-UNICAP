#include <stdio.h>
void troca_valor(char *p_c1, char *p_c2) {
    char temp = *p_c1;
    *p_c1 = *p_c2;
    *p_c2 = temp;
}

int main() {
    char c1 = 'A';
    char c2 = 'B';
    char *p_c1 = &c1;
    char *p_c2 = &c2;

    printf("ANTES:\nc1 = %c, endereço = %p\nc2 = %c, endereço = %p\n", *p_c1, p_c1, *p_c2, p_c2);
    troca_valor(p_c1, p_c2);
    printf("\nDEPOIS:\nc1 = %c, endereço = %p\nc2 = %c, endereço = %p\n", *p_c1, p_c1, *p_c2, p_c2);

    return 0;
}
