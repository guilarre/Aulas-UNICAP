#include<stdio.h>
#include <stdlib.h>
#define MAX 5

// TODO: inserir, acessar e remover vão atuar APENAS no final da lista (inserir_final, acessar_final, ...)

typedef struct lista {
    int dados[MAX];
    int qtd;
} *Lista;

Lista criar_lista(){
    Lista l = malloc(sizeof(struct lista));
    if(l != NULL)
        l->qtd = 0;
    return l;
}

int inserir(Lista l, int matricula, int pos){
    if(pos < MAX){
        l->dados[pos] = matricula;
        l->qtd++;
        return 0;
    }else
        return 1;
}

int acessar(Lista l, int pos, int* matricula){ // TODO: falta verificar se valor é "nulo". precisa ver qtd
    if (pos >= MAX || pos < 0)
        return 1;
    else
        *matricula = l->dados[pos];
        return 0;
}

int remover_elemento(Lista l, int pos) {
    return 0;
}

int tamanho_lista(Lista l) {
    if (l == NULL)
        return 0;
    return l->qtd;
}

void destruir_lista(Lista l) {
    if (l != NULL)
        free(l);
}

int main(){
    Lista l = criar_lista();
    int matricula;

    for(int i = 0; i < 2; i++){
        printf("Insira a matricula aluno %d: ", i+1);
        scanf("%d", &matricula);

        if(inserir(l, matricula, i)){
            printf("Erro, valor nao inserido\n");
        }else{
            printf("Valor %d inserido\n", matricula);
        }
        printf("Quantidade de elementos: %d\n", tamanho_lista(l));
    }
   
    for(int i = 0; i < tamanho_lista(l); i++){
        if (acessar(l, i, &matricula))
            printf("Matricula aluno %d: %d \n", i+1, matricula);
    }

    destruir_lista(l);
    return 0;
}
