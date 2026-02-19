#define N 5 // Número de círculos no vetor estático
#define pi 3.14

typedef struct Circulo_st* Circulo;

Circulo cria_circulo(float r); // r = raio
void destroi_circulo(Circulo c);
float acessa_raio(Circulo c);
float calcula_area(Circulo c);
float calcula_perimetro(Circulo c);

// Função para criar 5 círculos e armazenar em vetor
Circulo *criar_vetor_circulos();

// Funções para comparação entre círculos
void maior_area(Circulo *vetor_circulos);
void menor_area(Circulo *vetor_circulos);
void maior_perimetro(Circulo *vetor_circulos);
void menor_perimetro(Circulo *vetor_circulos);

// Destrutor do vetor
// void destruir_vetor_circulos(Circulo *vetor_circulos);
