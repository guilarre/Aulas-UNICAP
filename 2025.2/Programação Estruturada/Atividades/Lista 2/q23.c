#include <stdio.h>
int main() {
    int A, *B, **C, ***D;

    // Variável normal
    A = 2;

    // B aponta pro endereço da variável (precisa salvar em
    // outra variável pra não alterar B (e consequentemente A)
    // diretamente)
    B = &A;
    int dobro = *B * 2;

    // C aponta pro endereço do ponteiro
    C = &B;
    int triplo = **C * 3;

    // D aponta pro endereço do ponteiro de ponteiro
    D = &C;
    int quadruplo = ***D * 4;

    printf("%d, %d, %d, %d\n", A, dobro, triplo, quadruplo);

    return 0;
}
