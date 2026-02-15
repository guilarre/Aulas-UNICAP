#include <stdlib.h>
#include <stdio.h>
int main() {
    int n = 9;
    
    int *v;
    v = (int *) malloc(n * sizeof(int));
    
    // *(v) = 0;
    // *(v+1) = 1;
    // *(v+2) = 2;
    // *(v+3) = 3;
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    free(v);
    return 0;
}