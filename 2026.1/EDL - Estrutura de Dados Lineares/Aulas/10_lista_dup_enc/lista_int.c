#include<stdlib.h>
#include<stdio.h>

typedef struct elemento{
    int valor;
    struct elemento* prox;
    struct elemento* ant;
} Elem;

typedef struct lista{
    Elem* inicio;
    Elem* final;
    int qtd;
}* Lista;

Lista criar_lista(){
    Lista li = malloc(sizeof(struct lista));
    if(li != NULL){
        li->inicio = NULL;
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}

int inserir_inicio(Lista li, int valor){
    Elem* no = malloc(sizeof(Elem));
    if(no != NULL){
        no->valor = valor;
        no->prox = li->inicio;
        no->ant = NULL;
        
        if(li->inicio != NULL){
            li->inicio->ant = no;
        }else{
            li->final = no;
        }
        li->inicio = no;
        li->qtd++;
        return 0;
    }
    return 1;
}


int inserir_final(Lista li, int valor){
    if(li == NULL)
        return 1;
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL)
        return 1;
    no->valor = valor;
    no->prox = NULL;
    no->ant = li->final;
    if(li->final != NULL){
        li->final->prox = no;
    }else{
        li->inicio = no;
    }
    li->final = no;
    li->qtd++;
    return 0;
    
}

int remover_inicio(Lista li){
    if(li->inicio == NULL){
        return 1;
    }
    Elem* no = li->inicio;
    li->inicio = no->prox;
    li->inicio->ant = NULL;
    li->qtd--;
    free(no);
    return 0;
}

int remover_final(Lista li){
    if(li == NULL || li->inicio == NULL || li->qtd == 0)
        return 1;
    Elem* no = li->final;
    li->final = no->ant;

    if(li->final != NULL){
        li->final->prox = NULL;
    }else{
        li->inicio = NULL;
    }
    li->qtd--;
    free(no);
    return 0;
}

int acessar_inicio(Lista li, int* valor){
    if(li == NULL){
        return 1;
    }
    *valor = li->inicio->valor;
    return 0;
}

int acessar_final(Lista li, int* valor){
    if(li == NULL){
        return 1;
    }
    *valor = li->final->valor;
    return 0;
}

void destruir(Lista li){
    if(li != NULL){
        Elem* no = li->inicio;
        while(no != NULL){
            Elem *prox = no->prox;
            free(no);
            no = prox;
        }
        free(li);
    }
}

int lista_quantidade(Lista li){
    if(li == NULL)
        return 0;
    return li->qtd;
}

int tamanho_lista(Lista li){
    if(li == NULL)
        return 0;

    int count = 0;
    Elem* aux = li->inicio;
    while(aux != NULL){
        count++;
        aux = aux->prox;
    }
    return count;
}

// imprimir lista (inicio -> fim)
// imprimir lista inverso (fim -> inicio)
// acessar posicao
// remover posicao
// remover valor

int main(){
    Lista li = criar_lista();
    inserir_inicio(li, 20);
    inserir_inicio(li, 30);
    inserir_inicio(li, 40);
    int valor;
    acessar_inicio(li, &valor);
    printf("O valor do inicio é: %d\n", valor);

    printf("Tamanho da lista: %d\n", lista_quantidade(li));

    destruir(li);
    return 0;
}