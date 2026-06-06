// criar um número complexo
// destruir um número complexo
// soma de dois números complexos
// subtração de dois números complexos
// multiplicação de dois números complexos
// divisão de dois números complexos

#include <stdio.h>
#include <stdlib.h>

typedef struct complexo* Complexo;

Complexo criar_complexo(float x, float y);
void destruir_completo(Complexo c);
Complexo somar_complexos(Complexo c1, Complexo c2);
Complexo subtrair_complexos(Complexo c1, Complexo c2);
Complexo multiplicar_complexos(Complexo c1, Complexo c2);
Complexo dividir_complexos(Complexo c1, Complexo c2);
void printa_complexo(Complexo c1);
