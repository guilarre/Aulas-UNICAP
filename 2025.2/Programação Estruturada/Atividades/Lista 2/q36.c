#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
    char endereco[50];
};

int main() {
    struct Pessoa pessoa1;

    printf("Digite o nome da pessoa:\n");
    fgets(pessoa1.nome, 50, stdin);
    pessoa1.nome[strlen(pessoa1.nome) - 1] = '\0';

    printf("Digite a idade:\n");
    scanf("%d", &pessoa1.idade);
    getchar();

    printf("Digite o endereço:\n");
    fgets(pessoa1.endereco, 50, stdin);
    pessoa1.endereco[strlen(pessoa1.endereco) - 1] = '\0';

    printf("\nPessoa registrada:\n\n" \
            "Nome: %s\n" \
            "Idade: %d\n" \
            "Endereço: %s\n",
            pessoa1.nome, pessoa1.idade, pessoa1.endereco);

    return 0;
}
