#include <stdio.h>

int main() {
    int v[] = {1, 3, 5, 7, 9, 12, 15, 20}; /* ORDENADO */
    int n = sizeof(v)/sizeof(v[0]);
    int x = 12;

    int ini = 0;
    int fim = n - 1;
    int pos = -1;

    int idx = 0;
    int *p_idx = &idx;

    while (ini <= fim) {
        *p_idx += 1;
        int meio = (ini + fim) / 2;
        printf("loop #%d: início = %d | meio = %d | fim = %d\n", *p_idx, ini, meio, fim);
        if (v[meio] == x) { 
            pos = meio; 
            break; 
        }
        else 
            if (v[meio] < x) 
                ini = meio + 1;
            else
                fim = meio - 1;
    }

    if (pos == -1) 
        printf("Nao encontrado.\n");
    else
        printf("Binaria: %d encontrado em v[%d].\n", x, pos);

    return 0;
}




// int busca_binaria(int v[], int n, int x) {
//     int ini = 0, fim = n - 1;
//     while (ini <= fim) {
//         int meio = (ini + fim) / 2;
//         if (v[meio] == x)
//             return meio;
//         else if (v[meio] < x)
//             ini = meio + 1;
//         else
//             fim = meio - 1;
//     }
//     return -1;
// }
