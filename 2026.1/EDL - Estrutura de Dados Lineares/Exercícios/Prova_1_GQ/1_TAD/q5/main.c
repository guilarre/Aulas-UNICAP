#include "q5.h"
#include <stdio.h>

int main() {
    Conjunto A = criar_conjunto(5);
    Conjunto A2 = criar_conjunto(5);
    Conjunto B = criar_conjunto(5);
    inserir(A, 1);
    inserir(A, 2);
    inserir(A, 3);
    inserir(A, 4);
    inserir(A, 5);

    inserir(A2, 1);
    inserir(A2, 2);
    inserir(A2, 3);
    inserir(A2, 4);
    inserir(A2, 5);

    inserir(B, 6);
    inserir(B, 7);
    inserir(B, 8);
    inserir(B, 5);
    inserir(B, 10);

    Conjunto U = uniao(A, B);
    Conjunto I = intersecao(A, B);
    Conjunto D = diferenca(A, B);

    printf("A e B são iguais?\n");
    if (sao_iguais(A, B) == 1) printf("Sim\n"); else printf("Não\n");

    int elemento;
    menor(A, &elemento);
    printf("O menor de A é: %d\n", elemento);
    maior(A, &elemento);
    printf("O maior de A é: %d\n", elemento);
    printf("O tamanho de A é: %d\n", tamanho(A));
    printf("A é vazio?\n");
    if (vazio_teste(A) == 1) printf("Sim\n"); else printf("Não\n");
    Conjunto vazio = criar_conjunto(5);
    printf("'vazio' é vazio?\n");
    if (vazio_teste(vazio) == 1) printf("Sim\n"); else printf("Não\n");

    return 0;
}
