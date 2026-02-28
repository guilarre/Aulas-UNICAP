typedef struct Circulo* Circulo;

Circulo cria_circulo(float r); // r = raio
void destroi_circulo(Circulo c);
float acessa_raio(Circulo c);
float calcula_area(Circulo c);
float calcula_perimetro(Circulo c);
