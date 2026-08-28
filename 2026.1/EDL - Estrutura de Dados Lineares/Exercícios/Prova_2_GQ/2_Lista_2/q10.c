#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct produto {
	int codProd;
	char nomeProd[10];
	float valor;
	int qtdeEstoque;
} Produto;

typedef struct no {
    Produto *produto;
    struct no *prox;
} *No;

typedef struct lista {
    int qtd;
    No inicio;
} *Lista;

Lista cria_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li == NULL) return NULL;
    li->qtd = 0;
    li->inicio = NULL;
    return li;
}

int criar_produto(int codProd, char *nomeProd, float valor, int qtdeEstoque, Produto *produto) {
    if (strlen(nomeProd) > 10) return 1;
    (*produto).codProd = codProd;
    strcpy((*produto).nomeProd, nomeProd);
    (*produto).valor = valor;
    (*produto).qtdeEstoque = qtdeEstoque;
    return 0;
}

int insere_inicio(Lista li, Produto *produto) {
    if (li == NULL) return 1;
    No no = malloc(sizeof(struct no));
    if (no == NULL) return 1;
    no->produto = produto;
    if (li->qtd == 0) {
        no->prox = NULL;
    } else {
        no->prox = li->inicio;
    }
    li->inicio = no;
    li->qtd++;
    return 0;
}

int insere_final(Lista li, Produto *produto) {
    if (li == NULL) return 1;
    No no = malloc(sizeof(struct no));
    if (no == NULL) return 1;
    no->produto = produto;
    if (li->qtd == 0) {
        no->prox = NULL;
        li->inicio = no;
    } else {
        No aux = li->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    li->qtd++;
    return 0;
}

int remove_inicio(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    if (li->qtd == 1) {
        free(li->inicio);
        li->inicio = NULL;
    } else {
        No aux = li->inicio;
        li->inicio = li->inicio->prox;
        free(aux);
    }
    li->qtd--;
    return 0;
}

int remove_final(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    if (li->qtd == 1) {
        free(li->inicio);
        li->inicio = NULL;
    } else {
        No aux = li->inicio;
        li->inicio = li->inicio->prox;
        free(aux);
    }
    li->qtd--;
    return 0;
}

void destroi_lista(Lista li) {
    if (li != NULL) {
        if (li->qtd != 0) {
            No aux = li->inicio;
            No prox;
            while (aux != NULL) {
                prox = aux->prox;
                free(aux);
                aux = prox;
            }
        }
        free (li);
    }
}

void printa_lista(Lista li) {
    if (li != NULL && li->qtd != 0) {
        No aux = li->inicio;
        printf("\nProdutos na lista:\n");
        while (aux != NULL) {
            printf("Código: %d\n", aux->produto->codProd);
            printf("Nome: %s\n", aux->produto->nomeProd);
            printf("Valor: %f\n", aux->produto->valor);
            printf("Qtd em estoque: %d\n\n", aux->produto->qtdeEstoque);
            aux = aux->prox;
        }
    }
}

int buscar_mais_barato(Lista li, Produto *produto) {
    if (li == NULL || li->qtd == 0) return 1;
    No aux = li->inicio;
    Produto *menor = aux->produto;
    while (aux != NULL) {
        if (aux->produto->valor < menor->valor)
            menor = aux->produto;
        aux = aux->prox;
    }
    *produto = *menor;
    return 0;
}

int main() {
    Lista li = cria_lista();
    Produto produto;
    criar_produto(123, "bla", 123.3, 2, &produto);
    insere_final(li, &produto);

    Produto produto2;
    criar_produto(321, "zzzzzzz", 4.3333, 5, &produto2);
    insere_final(li, &produto2);

    printa_lista(li);

    Produto mais_barato;
    buscar_mais_barato(li, &mais_barato);
    printf("%f\n", mais_barato.valor);

    destroi_lista(li);

    return 0;
}
