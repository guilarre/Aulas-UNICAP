// FILA = FIFO (First In, First Out)

// Funções:
// cria_fila
// inserir (enqueue) - sempre no final
// remover (dequeue) - sempre do início
// acessar (getFront/getRear) - no nosso caso, sempre o início
// tamanho
// destruir_fila
// > pode ter tb um isEmpty()

// Variáveis pro struct fila
// inicio, final, dados, qtd (apesar de não necessário, pois dá p inferir pelo início e final)
// se início e final == 0, lista vazia
// se início e final != 0 e início == final, lista cheia

#include "fila_int.h"

struct fila {
    int dados[MAX];
    int inicio, final, qtd;
};


Fila cria_fila() {
    Fila f = malloc(sizeof(struct fila));
    if (f != NULL) {
        f->inicio = 0;
        f->final = 0;
        f->qtd = 0;
    }
    return f;
}

int inserir_fila(Fila f, int valor) {
    if (f->qtd < MAX && f != NULL) {
        f->dados[f->final] = valor;
        f->final = (f->final + 1) % MAX;
        f->qtd++;
        return 0;
    }
    return 1;
}

int remover_fila(Fila f) {
    if (f->qtd == 0 || f == NULL)
        return 1;
    else {
        f->inicio = (f->inicio + 1) % MAX;
        f->qtd--;
        return 0;
    }
    return 1;
}

// Acessa só o início p visualização
int acessar(Fila f, int* valor) {
    if (f->qtd == 0 || f == NULL)
        return 1;
    else {
        *valor = f->dados[f->inicio];
        return 0;
    }
    return 1;
}

int tamanho(Fila f) {
    if (f == NULL)
        return 0;
    else {
        return f->qtd;
    }
}

void destruir_fila(Fila f) {
    if (f != NULL) {
        free(f);
    }
}
