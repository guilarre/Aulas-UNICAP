#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento *prox;
} *Elem;

typedef struct lista {
    int qtd;
    Elem inicio;
} *Lista;

Lista cria_lista() {
    Lista li = malloc(sizeof(struct lista));
    if (li == NULL) return NULL;
    li->qtd = 0;
    li->inicio = NULL;
    return li;
}

int insere_inicio(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    if (no != NULL && li->qtd == 0) { //se lista vazia
        no->valor = valor;
        no->prox = NULL;
        li->inicio = no;
        li->qtd++;
        return 0;
    } else if (no != NULL && li->qtd > 0) {
        no->valor = valor;
        no->prox = li->inicio;
        li->inicio = no;
        li->qtd++;
        return 0;
    } else {
        return 1;
    }
}

int insere_final(Lista li, int valor) {
    if (li == NULL) return 1;
    Elem no = malloc(sizeof(struct elemento));
    no->valor = valor;
    no->prox = NULL;
    if (no != NULL && li->qtd == 0) { //se vazia
        li->inicio = no;
        li->qtd++;
        return 0;
    } else if (no != NULL && li->qtd > 0) {
        //percorrer até último
        Elem aux = li->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
        li->qtd++;
        return 0;
    }
    return 1;
}

int remove_inicio(Lista li) {
    if (li == NULL || li->qtd <= 0) return 1;
    else {
        Elem aux = li->inicio;
        li->inicio = aux->prox;
        free(aux);
        li->qtd--; return 0;
    }
}

int remove_final(Lista li) {
    if (li == NULL || li->qtd <= 0) return 1;
    else {
        Elem aux = li->inicio;
        // se só tiver 1 elem na lista
        if (aux->prox == NULL) {
            li->inicio = NULL; //precisa?
            free(aux);
            li->qtd--;
            return 0;
        } else { //mais de 1 elem na lista
            Elem anterior; //antes do último
            while (aux->prox != NULL) {
                anterior = aux;
                aux = aux->prox;
            }
            anterior->prox = NULL; //precisa?
            free(aux);
            li->qtd--;
            return 0;
        }
    }
}

void libera_lista(Lista li) {
    if (li == NULL) return;
    Elem aux = li->inicio;
    Elem prox;
    while (aux != NULL) {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
    free(li);
}

int lista_vazia(Lista li) { //1 = sim, 0 = não
    if (li == NULL || li->qtd <= 0) return 1;
    else return 0;
}

int tamanho_lista(Lista li) {
    if (li == NULL || li->qtd <= 0) return 0;
    else return li->qtd;
}

void imprime_lista(Lista li) {
    if (li == NULL || li->qtd <= 0) return;
    else {
        Elem aux = li->inicio;
        while (aux->prox != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        print("\n");
    }
}

void imprime_lista_reverso(Lista li) {
    if (li == NULL || li->qtd <= 0) return;
    else {
        Elem aux = li->inicio;
        Elem arraypos[li->qtd]; //ponteiro de ponteiros
        int i = 0;
        while (aux->prox != NULL) {
            arraypos[i] = aux;
            i++;
            aux = aux->prox;
        }
        for (int j = 0; j < li->qtd; j++) {
            printf("%d ", arraypos[i]->valor);
            i--;
        }
        printf("\n");
    }
}

Elem busca_valor(Lista li, int valor) {
    if (li == NULL || li->qtd <= 0) return NULL
    else {
        Elem aux = li->inicio;
        while (aux->prox != NULL) {
            if (aux->valor == valor) {
                return aux;
            } // TODO:
            aux = aux->prox;
        }
    }
}

int main() {
    return 0;
}
