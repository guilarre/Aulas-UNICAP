// Lista encadeada (dinâmica)
// criar
// inserir_inicio
// remover_inicio
// acessar_inicio
// destruir
// aula 2: inserir_final, remover_final
// aula 3: colocou qtd em lista e colocou Elem como ponteiro

#include <stdlib.h>
#include <stdio.h>

typedef struct elemento {
    int valor;
    struct elemento* prox;
} *Elem;

typedef struct lista {
    int qtd;
    Elem inicio;
} *Lista;

Lista criar_lista() {
    Lista li = malloc(sizeof(Lista));
    if (li != NULL) {
        li->inicio = NULL;
        li->qtd = 0;
    }
    return li;
}

int inserir_inicio(Lista li, int valor) {
    Elem no = malloc(sizeof(struct elemento));
    if (li->qtd > 0 && no != NULL) {
        no->valor = valor;
        no->prox = li->inicio;
        li->inicio = no;
        li->qtd++;
        return 0;
    } else if (li->qtd == 0 && no != NULL) { // caso de li vazia
        no->valor = valor;
        no->prox = NULL;
        li->inicio = no;
        li->qtd++;
        return 0;
    }
    return 1;
}

int remover_inicio(Lista li) {
    if (li->qtd > 0) {
        Elem no = li->inicio;
        li->inicio = no->prox;
        free(no);
        li->qtd--;
        return 0;
    }
    return 1;
}

int acessar_inicio(Lista li, int* valor) {
    if (li != NULL) {
        *valor = li->inicio->valor;
        return 0;
    }
    return 1;
}

void destruir(Lista li) {
    if (li != NULL) {
        Elem no = li->inicio;
        while (no != NULL) {
            Elem prox = no->prox;
            free(no);
            no = prox;
        }
        free(li);
    }
}

int tamanho_lista(Lista li) {
    if (li == NULL)
        return 0;
    return li->qtd;
}

int inserir_final(Lista li, int valor) {
    if (li != NULL) {
        // Cria o nó
        Elem no = malloc(sizeof(Elem));
        if (no == NULL)
            return 1;
        no->valor = valor;
        no->prox = NULL;

        // Se lista estiver vazia
        if (li->qtd == 0) {
            li->inicio = no;
            li->qtd++;
            return 0;
        }

        // Se lista tiver elementos, vai percorrer lista e
        // adicionar o nó criado ao último elem
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

int remover_final(Lista li) {
    if (li != NULL && li->qtd > 0) {
        Elem aux = li->inicio;
        Elem ant;

        // Caso só tenha 1 elem
        if (aux->prox == NULL) {
            free(aux);
            li->qtd--;
            return 0;
        }

        // Caso contrário, percorre até o último elem
        while (aux->prox != NULL) {
            ant = aux;
            aux = aux->prox;
        }
        free(aux);
        ant->prox = NULL;
        li->qtd--;
        return 0;
    }
    return 1;
}

int acessar_final(Lista li, int* valor) {
    if (li != NULL) {
        Elem aux = li->inicio;
        while (aux != NULL) {
            aux = aux->prox;
        }
        *valor = aux->valor;
        return 0;
    }
    return 1;
}

int main() {
    Lista li = criar_lista();

    inserir_inicio(li, 20);
    inserir_inicio(li, 30);
    inserir_inicio(li, 40);

    int valor;
    acessar_inicio(li, &valor);
    printf("O valor do início é: %d", valor);

    return 0;
}
