#include <stdio.h>
int main() {
    float f1 = 1.4;
    float f2 = 999.9;

    float *p;

    p = &f1;
    printf("ANTES (f1): Endereço de *p = %p; Valor = %f\n", p, *p);
    *p = 99.8;
    printf("DEPOIS (f1): Endereço de *p = %p; Valor = %f\n", p, *p);

    p = &f2;
    printf("ANTES (f2): Endereço de *p = %p; Valor = %f\n", p, *p);
    *p = 123.4;
    printf("DEPOIS (f2): Endereço de *p = %p; Valor = %f\n", p, *p);

    return 0;
}
