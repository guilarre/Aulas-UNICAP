#include"aluno.h"
#include<stdlib.h>

struct aluno{
    int mat;
    float media;
};

Aluno criar_aluno(int mat, float media){
    Aluno a = malloc(sizeof(struct aluno));

    if(a != NULL){
        a->mat = mat;
        a->media = media;
    }
    return a;
}

int acessar_mat (Aluno a) {
    return a->mat;
}

float acessar_media (Aluno a) {
    return a->media;
}

void destruir (Aluno a) {
    if (a != NULL)
        free(a);
}

// Fila
struct fila {
    Aluno alunos[MAX];
    int inicio, final, qtd;
};

Fila criar_fila() {
    Fila f = malloc(sizeof(struct fila));
    if (f != NULL) {
        f->inicio = 0;
        f->final = 0;
        f->qtd = 0;
    }
    return f;
}

int inserir_fila(Fila f, Aluno a) {
    if (f != NULL && f->qtd < MAX) {
        f->alunos[f->final] = a;
        f->final = (f->final + 1) % MAX;
        f->qtd++;
        return 0;
    }
    return 1;
}

int remover_fila(Fila f) {
    if (f != NULL && f->qtd > 0) {
        f->inicio = (f->inicio + 1) % MAX;
        f->qtd--;
        return 0;
    }
    return 1;
}

int acessar_fila(Fila f, Aluno* a) {
    if (f != NULL && f->qtd > 0) {
        *a = f->alunos[f->inicio];
        return 0;
    }
    return 1;
}

int tamanho_fila(Fila f) {
    if (f == NULL || f->qtd > 0) {
        return 0;
    } else {
        return f->qtd;
    }
}
void destruir_fila(Fila f) {
    if (f != NULL)
        free(f);
}
