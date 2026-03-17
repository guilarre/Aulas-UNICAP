#define MAX 5

// Dados
typedef struct aluno* Aluno;

// Operacoes
Aluno criar_aluno(int mat, float media);
int acessar_mat(Aluno a);
float acessar_media(Aluno a);
void destruir(Aluno a);

// Fila para alunos
typedef struct fila *Fila;
Fila criar_fila();
int inserir_fila(Fila f, Aluno a);
int remover_fila(Fila f);
int acessar_fila(Fila f, Aluno* a);
int tamanho_fila(Fila f);
void destruir_fila(Fila f);
