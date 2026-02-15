#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int qtd;
};

typedef struct Produto produto;

produto cria_produto(char nome[], float preco, int qtd) {
    produto p;

    strcpy(p.nome, nome);
    p.preco = preco;
    p.qtd = qtd;

    return p;
}

float valor_total(produto p) {
    float valor_total = p.preco * p.qtd;

    return valor_total;
}

int main() {
    produto p1 = cria_produto("Pão de caixa", 9.98, 50);

    printf("Produto em estoque:\n" \
           "\nNome: %s" \
           "\nPreço: R$%.2f" \
           "\nQuantidade: %d\n", p1.nome, p1.preco, p1.qtd);

    printf("\nValor total do produto em estoque: R$%.2f\n", valor_total(p1));

    return 0;
}
