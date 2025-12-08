#include <stdio.h>
int main() {
    float v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(v)/sizeof(float);
    for (int i = 0; i < n; i++) {
        printf("&v[%d] = %p\n", i, &v[i]);
    }

    return 0;
}
