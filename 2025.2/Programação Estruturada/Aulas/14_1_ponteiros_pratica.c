#include <stdio.h>
int main() {
  float x = 20;
  float y = 100;

  // Apontando pra x
  float *p = &x;
  printf("x (antes) = %f\n", *p);
  printf("&x = %p\n", p);

  // Alterando valor de x
  *p += 3;
  printf("x (depois) = %f\n", *p);
  printf("&x = %p\n", p);

  printf("\nAlterando ponteiro...\n");

  // Apontando pra y
  p = &y;
  printf("y (antes) = %f\n", *p);
  printf("&y = %p\n", p);

  // Alterando valor de y
  *p *= 3;
  printf("y (depois) = %f\n", *p);
  printf("&y = %p\n", p);

  return 0;
}
