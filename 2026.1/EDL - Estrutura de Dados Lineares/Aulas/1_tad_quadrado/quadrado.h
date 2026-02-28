// tipo opaco (quem usa a biblioteca .h não vê o que tá dentro da struct):
typedef struct Quadrado* Quadrado; // Criando um ponteiro pra implementação do struct (no .c)

Quadrado cria_quadrado(float l);
void destruir_quadrado(Quadrado q);
float acessa_lado(Quadrado q);
float calculo_area(Quadrado q);
float calculo_perimetro(Quadrado q);