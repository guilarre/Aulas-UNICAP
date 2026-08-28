#include <stdlib.h>
#include <stdio.h>

// 9. Dada uma lista que armazena dados do tipo char, implemente uma função que
// remova todas as ocorrências do caractere passado como parâmetro. A função
// deve retornar se a operação foi possível ou não.

// (implementando como circular pra treinar mais)

typedef struct no {
    char valor;
    struct no *prox;
} *No;

typedef struct lista_circ {
    int qtd;
    No final;
} *Lista;

Lista cria_lista() {
    Lista li = malloc(sizeof(struct lista_circ));
    if (li == NULL) return NULL;
    li->qtd = 0;
    li->final = NULL;
    return li;
}

int insere_inicio(Lista li, char valor) {
    if (li == NULL) return 1;
    No no = malloc(sizeof(struct no));
    if (no == NULL) return 1;
    no->valor = valor;
    if (li->final == NULL) { //msm que li->qtd == 0
        no->prox = no;
        li->final = no;
    } else {
        no->prox = li->final->prox;
        li->final->prox = no;
    }
    li->qtd++;
    return 0;
}

int insere_final(Lista li, char valor) {
    if (li == NULL) return 1;
    No no = malloc(sizeof(struct no));
    if (no == NULL) return 1;
    no->valor = valor;
    if (li->final == NULL) //0 elem
        no->prox = no;
    else {
        no->prox = li->final->prox;
        li->final->prox = no;
    }
    li->final = no;
    li->qtd++;
    return 0;
}

int remove_inicio(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    if (li->final->prox == li->final) { //só 1 elem
        free(li->final);
        li->final = NULL;
    } else {
        No prox = li->final->prox->prox;
        free(li->final->prox);
        li->final->prox = prox;
    }
    li->qtd--;
    return 0;
}

int remove_final(Lista li) {
    if (li == NULL || li->qtd == 0) return 1;
    if (li->final->prox == li->final) { //só 1 elem
        free(li->final);
        li->final = NULL;
    } else {
        No aux = li->final->prox;
        No ant;
        while (aux->prox != li->final->prox) {
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = aux->prox;
        li->final = ant;
        free(aux);
    }
    li->qtd--;
    return 0;
}

void printa_lista(Lista li) {
    if (li != NULL && li->qtd != 0) {
        No aux = li->final->prox;
        printf("Lista = [ ");
        do {
            printf("%c ", aux->valor);
            aux = aux->prox;
        } while (aux != li->final->prox);
        printf("]\n");
    } else printf("[ ]\n");
}

void destroi_lista(Lista li) {
    if (li != NULL) {
        if (li->qtd != 0) {
            No aux = li->final->prox;
            No prox;
            for (int i = 0; i < li->qtd; i++) {
                prox = aux->prox;
                free(aux);
                aux = prox;
            }
        }
        free(li);
    }
}

int remove_char_lista(Lista li, char valor) {
    if (li == NULL || li->qtd == 0) return 1;
    No aux = li->final->prox;
    int removeu_sucesso = 0;
    for (int i = 0; i < li->qtd; i++) {
        if (li->qtd == 1) {
            if (aux->valor == valor) {
                free(li->final);
                li->final = NULL;
                li->qtd--;
                return 0;
            }
        } else if (aux->valor == valor) {
            No no_a_remover = li->final->prox;
            No ant;
            while (no_a_remover != aux) {
                ant = no_a_remover;
                no_a_remover = no_a_remover->prox;
            }
            ant->prox = no_a_remover->prox;
            if (aux == li->final) li->final = ant;
            free(no_a_remover);
            li->qtd--;
            //volta pro começo pra checar o restante
            aux = li->final->prox;
            i = -1;
            printf("## APÓS REMOÇÃO ##\n");
            printa_lista(li);
            printf("\n");
            removeu_sucesso = 1; //pro retorno no final
        } else aux = aux->prox;
    }

    if (removeu_sucesso) return 0;
    return 1;
}

int main() {
    Lista li = cria_lista();
    insere_final(li, 'a');
    insere_final(li, 'b');
    insere_final(li, 'c');
    insere_final(li, 'c');
    insere_final(li, 'd');
    remove_inicio(li);
    insere_inicio(li, 'e');
    insere_inicio(li, 'f');
    insere_inicio(li, 'g');
    insere_inicio(li, 'h');
    remove_final(li);

    printf("\n## APÓS INSERÇÃO ##\n");
    printa_lista(li);
    printf("\n");

    remove_char_lista(li, 'f');
    remove_char_lista(li, 'c');
    remove_char_lista(li, 'b');
    remove_char_lista(li, 'h');

    destroi_lista(li);

    return 0;
}
