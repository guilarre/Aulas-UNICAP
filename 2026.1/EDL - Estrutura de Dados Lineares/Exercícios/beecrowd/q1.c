#include <stdio.h>
#include <math.h>

float distance(float x1, float x2, float y1, float y2) {
    float d = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
    return d;
}

int main() {
    float x1, x2, y1, y2;
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);

    printf("%.4f\n", distance(x1, x2, y1, y2));

    return 0;
}
