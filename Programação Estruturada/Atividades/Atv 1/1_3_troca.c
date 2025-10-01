#include <stdio.h>
int main() {
    int a, b;

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    printf("Antes da troca: a = %d, b = %d\n", a, b);
    
    // Criando ponteiros
    int* a_ptr = &a;
    int* b_ptr = &b;

    // Lógica pra trocar ponteiros

    // Precisa criar uma variável normal temporária
    // pra que o ponteiro de a não seja sobrescrito
    int temp = *a_ptr;

    // Trocando os valores a partir dos ponteiros
    *a_ptr = *b_ptr;
    *b_ptr = temp;

    // Valores novos
    printf("Depois da troca: a = %d, b = %d\n", a, b);
}