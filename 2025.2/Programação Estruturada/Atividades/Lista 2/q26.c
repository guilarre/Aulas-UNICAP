#include <stdio.h>
void frac_func(float num, int *inteiro, float *frac) {
    *inteiro = (int)num;
    *frac = num - *inteiro;
}

int main() {
    float num = 122.32341;
    int inteiro;
    float frac;

    frac_func(num, &inteiro, &frac);

    printf("Número original = %f\nParte inteira = %d\nParte fracionária = %f", num, inteiro, frac);

    return 0;
}
