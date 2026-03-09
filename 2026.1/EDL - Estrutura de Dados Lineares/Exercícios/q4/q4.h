// criar um número complexo
// destruir um número complexo
// soma de dois números complexos
// subtração de dois números complexos
// multiplicação de dois números complexos
// divisão de dois números complexos

#include <stdio.h>
#include <stdlib.h>

typedef struct complexo *Complexo;

Complexo criar_complexo();
void destruir_completo(Complexo c);
int somar_complexos(Complexo c1, Complexo c2, Complexo c3);
int subtrair_complexo(Complexo c1, Complexo c2, Complexo c3);
int multiplicar_complexo(Complexo c1, Complexo c2, Complexo c3);
int dividir_complexo(Complexo c1, Complexo c2, Complexo c3);
