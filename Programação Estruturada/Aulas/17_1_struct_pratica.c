/*
Atividade
Crie uma struct chamada "Produto" com nome, preço e quantidade usando uma funcao cria_produto
Faça uma função valor_total que receba um Produto e retorne seu valor total (preço * quantidade).
Imprima as variáveis da struct Produto e o resultado de valor total
*/

#include <stdio.h>
#include <string.h>
struct Produto {
  char nome[50];
  float preco;
  int qtd;
};

struct Produto cria_produto(char nome[], float preco, int qtd) {
  struct Produto p;

  strcpy(p.nome, nome);
  p.preco = preco;
  p.qtd = qtd;

  return p;
};

float valor_total(struct Produto p) {
  return (p.preco * p.qtd);
}

int main() {
  struct Produto p1 = cria_produto("Mentos Kiss", 15, 50);
  printf("## Struct Produto ##\nNome: %s\nPreço: %.2f\nQuantidade: %d\n", p1.nome, p1.preco, p1.qtd);
  printf("\n## Valor total: %.2f", valor_total(p1));

  return 0;
}
