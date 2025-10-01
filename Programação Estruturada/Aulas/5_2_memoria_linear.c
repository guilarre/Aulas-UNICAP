#include <stdio.h>

int main() {
    int mat[3][3] = {
            {11, 12, 13},
            {21, 22, 23},
            {31, 32, 33}
        };

    int *p = &mat[0][0];
    for (int k = 0; k < 9; k++) {
        printf("*(p+%d) = %d\t%p\n", k, *(p+k), (p+k));
    }
}