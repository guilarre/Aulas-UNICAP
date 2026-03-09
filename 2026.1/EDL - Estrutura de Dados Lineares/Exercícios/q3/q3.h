// TAD para cilindro

// criar_cilindro()
// altura_cilindro()
// raio_cilindro()
// calcula_area()
// calcula_volume()
// destruir_cilindro()

#define PI 3.14
#include <stdio.h>
#include <stdlib.h>

typedef struct cilindro *Cilindro;

Cilindro criar_cilindro();
int altura_cilindro(Cilindro c, float *altura);
int raio_cilindro(Cilindro c, float *raio);
int area_cilindro(Cilindro c, float *area);
int volume_cilindro(Cilindro c, float *volume);
void destruir_cilindro(Cilindro c);
