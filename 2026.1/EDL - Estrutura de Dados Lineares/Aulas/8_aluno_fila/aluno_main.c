#include"aluno.h"
#include<stdio.h>

int main(){
    Fila f = criar_fila();
    Aluno a1 = criar_aluno(123, 6.0);
    Aluno a2 = criar_aluno(124, 6.5);
    Aluno a3 = criar_aluno(125, 7.8);

    Aluno aux;

    inserir_fila(f, a1);
    inserir_fila(f, a2);
    inserir_fila(f, a3);

    acessar_fila(f, &aux);
    printf("Primeiro aluno: mat = %d; media = %f\n", acessar_mat(aux), acessar_media(aux));

    destruir_fila(f);
    destruir(a1);
    destruir(a2);
    destruir(a3);
    return 0;
}
