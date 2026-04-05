#include "q5.h"

Conjunto criar_conjunto(int capacidade) {
    Conjunto c = malloc(sizeof(struct conjunto));
    if (c == NULL) return NULL; // caso de erro

    c->tamanho = 0;
    c->capacidade = capacidade;
    c->elementos = malloc(sizeof(int) * c->capacidade);
    if (c->elementos == NULL) {
        free(c);
        return NULL;
    }

    return c;
}

int pertence(Conjunto A, int elemento) {
    if (A != NULL) {
        int pertence = 0; // 0 = false
        for (int i = 0; i < A->tamanho; i++) {
            // 1 = true
            if (A->elementos[i] == elemento) {
                pertence = 1;
                break;
            }
        }
        return pertence;
    }
    // Caso A == NULL:
    printf("Conjunto inexistente\n");
    return -1; // A inexistente
}

int inserir(Conjunto A, int elemento) {
    if (A != NULL) {
        // índice onde inserir
        int idx = -1; 
        if (A->tamanho == 0) {
            idx = 0;
        } else if (A->tamanho > 0 && A->tamanho < A->capacidade) {
            idx = A->tamanho;
        } else {
            return 1;
        }

        // checando se já pertence ao conjunto
        int p = pertence(A, elemento);
        if (p == 1) {
            printf("Elemento já pertence ao conjunto\n");
            return 1;
        } else if (p == -1) return 1;
        else { // não pertence ainda
            A->elementos[idx] = elemento;
            A->tamanho++;
            return 0;
        }
    }
    return 1;
}

int remover(Conjunto A, int elemento) {
    if (A != NULL) {
        if (A->tamanho <= 0) return 1; // checa 1º se é vazio
        if (pertence(A, elemento) == 1) {
            int idx = -1;
            // pega o índice do elem a remover
            for (int i = 0; i < A->tamanho; i++) {
                if (A->elementos[i] == elemento) {
                    idx = i;
                    break;
                }
            }
            // substituir o atual pelo último elem e decrementar
            // tamanho do conjunto
            A->elementos[idx] = A->elementos[A->tamanho-1];
            A->tamanho--;
            return 0;
        }
    }
    return 1;
}

Conjunto uniao(Conjunto A, Conjunto B) {
    if (A != NULL && B != NULL) {
        int cap_C = A->tamanho + B->tamanho;
        Conjunto C = criar_conjunto(cap_C);
        if (C == NULL) return NULL;

        // Copia de A
        for (int i = 0; i < A->tamanho; i++) {
            C->elementos[C->tamanho++] = A->elementos[i];
        }
        // Adiciona de B se já não estiver em C
        for (int i = 0; i < B->tamanho; i++) {
            if (pertence(C, B->elementos[i]) == 0) {
                C->elementos[C->tamanho++] = B->elementos[i];
            }
        }
        return C;
    }
    return NULL;
}

Conjunto intersecao(Conjunto A, Conjunto B) {
    if (A != NULL && B != NULL) {
        int cap_C = -1;
        if (A->tamanho < B->tamanho) {
            cap_C = A->tamanho;
        } else {
            cap_C = B->tamanho;
        }
        Conjunto C = criar_conjunto(cap_C);
        if (C == NULL) return NULL;

        // Percorre A, se pertence a B, adiciona a C
        for (int i = 0; i < A->tamanho; i++) {
            if (pertence(B, A->elementos[i]) == 1) {
                C->elementos[C->tamanho++] = A->elementos[i];
            }
        }
        return C;
    }
    return NULL;
}

Conjunto diferenca(Conjunto A, Conjunto B) {
    if (A != NULL && B != NULL) {
        Conjunto C = criar_conjunto(A->tamanho);
        if (C == NULL) return NULL;

        // Percorre A, se NÃO pertencer a B, adiciona a C
        for (int i = 0; i < A->tamanho; i++) {
            if (pertence(B, A->elementos[i]) == 0) {
                C->elementos[C->tamanho++] = A->elementos[i];
            }
        }
        return C;
    }
    return NULL;
}

int sao_iguais(Conjunto A, Conjunto B) { // 0 = false, 1 = true
    if (A != NULL && B != NULL) {
        if (A->tamanho != B->tamanho) return 0; // tamanhos dif.
        for (int i = 0; i < A->tamanho; i++) {
            if (pertence(B, A->elementos[i]) <= 0) return 0;
        }
        return 1;
    }
    return 0;
}

void menor(Conjunto A, int *elemento) {
    if (A != NULL) {
        int menor_num = A->elementos[0];
        for (int i = 1; i < A->tamanho; i++) {
            if (A->elementos[i] < menor_num) {
                menor_num = A->elementos[i];
            }
        }
        *elemento = menor_num;
    }
    return;
}

void maior(Conjunto A, int *elemento) {
    if (A != NULL) {
        int maior_num = A->elementos[0];
        for (int i = 1; i < A->tamanho; i++) {
            if (A->elementos[i] > maior_num) {
                maior_num = A->elementos[i];
            }
        }
        *elemento = maior_num;
    }
    return;
}

int tamanho(Conjunto A) {
    if (A != NULL) {
        return A->tamanho;
    }
    return 0;
}

int vazio_teste(Conjunto A) { // 0 = false, 1 = true
    if (A != NULL) {
        if (A->tamanho > 0) return 0;
        else return 1;
    }
    return 1;
}
