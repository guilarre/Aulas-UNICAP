#include <math.h>
#include <stdio.h>
int main() {
  // Recebendo os valores do teclado
  double a, b, c, x;
  printf("Digite o valor de a:\n");
  scanf("%lf", &a);
  printf("Digite o valor de b:\n");
  scanf("%lf", &b);
  printf("Digite o valor de c:\n");
  scanf("%lf", &c);

  // Declarando delta (f não é necessário)
  // double f = a * (x * x) + b * x + c;
  double delta = (b * b) - 4 * a * c;

  // Printando valores de x se existirem
  if (a == 0) {
    printf("Não é equação de segundo grau\n");
  } else if (delta < 0) {
    printf("Não existe raiz real\n");
  } else if (delta == 0) {
    printf("Raiz única:\n");
    double x1 = (-b + sqrt(delta)) / (2 * a);
    printf("x = %.2lf\n", x1);
  } else if (delta > 0) {
    printf("Duas raízes:\n");
    double x1 = (-b + sqrt(delta)) / (2 * a);
    double x2 = (-b - sqrt(delta)) / (2 * a);
    printf("x1 = %.2lf\n", x1);
    printf("x2 = %.2lf\n", x2);
  }

  return 0;
}
