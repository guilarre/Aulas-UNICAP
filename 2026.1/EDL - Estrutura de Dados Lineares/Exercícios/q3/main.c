#include "q3.h"
int main() {
    // Criar cilindro
    Cilindro c = criar_cilindro();

    // Verificando as funções
    float altura;
    float raio;
    float area;
    float volume;

    if (altura_cilindro(c, &altura))
        return 1;
    if (raio_cilindro(c, &raio))
        return 1;
    if (area_cilindro(c, &area))
        return 1;
    if (volume_cilindro(c, &volume))
        return 1;

    printf("O cilindro criado possui altura %.2f u.c., raio %.2f u.c., area %.2f u.a. e volume %.2f u.v.\n", altura, raio, area, volume);

    return 0;
}
