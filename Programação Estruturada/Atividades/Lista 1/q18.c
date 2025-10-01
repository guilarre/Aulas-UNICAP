#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int var_1 = 1;
    int var_2 = 2;
    int *p1 = &var_1;
    int *p2 = &var_2;

    printf("\nvar_1 = %d, endereço = %p\n", *p1, p1);
    printf("var_2 = %d, endereço = %p\n", *p2, p2);

    if (p1 > p2) {
        printf("\nO maior endereço é: %p\n", p1);
    } else {
        printf("\nO maior endereço é: %p\n", p2);
    }

    return 0;
}