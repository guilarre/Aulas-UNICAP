#include <stdlib.h>
#include "quadrado.h"

// Definindo aqui, não podemos acessar dentro da main diretamente,
// somente através dos métodos de acesso (getter/setter)
// NOTE: outra vantagem = não cria uma cópia no escopo das funções,
// você acessa diretamente e não duplica um atributo 
struct quadrado {
    float l;
};

struct lista {
    Quadrado lista[TAM];
    int qtd;
};

Quadrado cria_quadrado(float l) {
    if (l < 0)
        l *= -1;
 
    Quadrado q = malloc(sizeof(struct quadrado));
    if (q != NULL)
        q->l = l; // pra acessar o membro de um struct através de um ponteiro
        // dá pra fazer (*q).l também -- desreferenciação --, em vez de q->l
 
    return q;
}

// destrutor
void destruir_quadrado(Quadrado q) {
    free(q);
}

float acessa_lado(Quadrado q) {
    return q->l;
}

float calculo_area(Quadrado q){
    return q->l * q->l;
}

float calculo_perimetro(Quadrado q){
    return 4 * (q->l);
}

// Funções CRUD relacionadas a listas
Lista cria_lista(Quadrado *lista) {
    // TODO:
}

int inserir_lista(Quadrado *lista);

int acessar_lista(Quadrado *lista);

void alterar_lista(Quadrado *lista);

void destroi_lista(Quadrado *lista);
