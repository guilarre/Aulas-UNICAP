#include <stdio.h>
#include <string.h>
int main() {
  char s1[50] = "Oi eu sou uma string";
  char s2[50] = "Xau";
  char s3[50];

  if (strlen(s1) > strlen(s2)) {
    strcpy(s3, s2);
  } else {
    strcpy(s3, s1);
  }

  printf("%s\n", s3);
  return 0;
}
