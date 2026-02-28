// Reutilizando o código do arquivo anterior:
// Dá erro pq teria 2 main
// #include "quadrado.c"

// Criamos o arquivo "quadrado.h" e passamos o struct e
// os protótipos das funções

#include "quadrado.h"

// Precisa separar a main tb (quadrado_main.c)
// Ordem dos arquivos .c não importa:
// gcc quadrado.c exercicio1.c -o exercicio1

int main() {
    quadrado q;
    q.l = 10;

    calcular_area(q);
}
