#define PI 3.14

typedef struct Circulo_st* Circulo;

Circulo cria_circulo(float r); // r = raio
void destroi_circulo(Circulo c);
float acessa_raio(Circulo c);
float calcula_area(Circulo c);
float calcula_perimetro(Circulo c);

// Função para criar círculos e armazenar em vetor
Circulo *criar_vetor_circulos(int n);

// Funções para comparação entre círculos
void maior_area(Circulo *vetor_circulos, int n);
void menor_area(Circulo *vetor_circulos, int n);
void maior_perimetro(Circulo *vetor_circulos, int n);
void menor_perimetro(Circulo *vetor_circulos, int n);
