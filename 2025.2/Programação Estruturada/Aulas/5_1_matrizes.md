# Vetor vs. matriz
- Vetor é um conjunto de dados unidimensional;
- Matriz é um conjunto de vetores (n dimensões);

## Vetor:
```C
#include <stdio.h>

int main() {
    int v[5]; // Tamanho do array
    v[0] = 4;

    printf("%d\n", v[0]);
    return 0;
}
```

## Matriz:

```C
...
int main() {
    int m[2][2]; // Matriz 2x2
    m[0][1] = 5; // Acesso pelos índices (linha, coluna)

    printf("%d\n", m[0][1]);
    return 0;
}
```

Lendo valores do terminal:

```C
...
int main() {
    float m[2][2]; // Matriz 2x2
    // Recebendo valores do terminal p/ cada elemento
    scanf("%f", &m[0][0]);
    scanf("%f", &m[0][1]);
    scanf("%f", &m[1][0]);
    scanf("%f", &m[1][1]);

    printf("%.2f\n", m[0][1]);
    printf("%.2f\n", m[1][1]);
    printf("%.2f\n", m[1][0]);
    printf("%.2f\n", m[1][1]);
    return 0;
}
```

Evitando repetição de código usando um **loop**:

```C
...
int main() {
    float m[2][2]; // Matriz 2x2

    // Loop aninhado pra iterar M(i, j)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%f", &m[i][j]);
        }
    }

    // Printando através de loop
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("m[%d][%d]: %.2f\n", i, j, m[i][j]);
        }
    }
    return 0;
}
```

Somando todos os elementos da matriz

```C
...
int main() {
    ... // Definindo matriz e lendo valores do teclado
    
    // Definir soma como 0 pra evitar lixo de memória
    float soma = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            soma += m[i][j];
        }
    }

    // Printando valor da soma
    printf("Soma: %.2f\n", soma);

    return 0;
}
```

Declarando a matriz estaticamente

```C
...
int main() {
    ... 
    // Pode usar {} pra definir valores de mesmo tipo do array
    int v[3] = {11, 12, 13};

    int mat[3][3] = {
        {11, 12, 13},
        {21, 22, 23},
        {31, 32, 33}
    };
}
```

É possível usar ponteiros pra ler matrizes

```C
...
    int *p = &mat[0][0];
    for (int k = 0; k < 9; k++) {
        printf("*(p+%d) = %d\t%p\n", k, *(p+k), (p+k));
    }
```