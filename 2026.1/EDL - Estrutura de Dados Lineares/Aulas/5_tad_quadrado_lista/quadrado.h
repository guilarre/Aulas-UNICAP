#define TAM 5

// tipo opaco (quem usa a biblioteca .h não vê o que tá dentro da struct):
typedef struct quadrado* Quadrado; // Criando um ponteiro pra implementação do struct (no .c)

Quadrado cria_quadrado(float l);
void destruir_quadrado(Quadrado q);
float acessa_lado(Quadrado q);
float calculo_area(Quadrado q);
float calculo_perimetro(Quadrado q);

// Funções CRUD relacionadas a listas
// NOTE: a ideia é controlar o input e gerenciamento da lista
typedef struct lista* Lista;
Lista cria_lista(Quadrado *lista);
int inserir_lista(Quadrado *lista);
int acessar_lista(Quadrado *lista);
void alterar_lista(Quadrado *lista);
void destroi_lista(Quadrado *lista);
