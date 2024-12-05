#include <stdio.h>

int main(){

  int x = 10 / 3 * 3;

  int a = 5;
  int b = a++ + 3;

  int m = 10;
  int n = (m%5) ? 4 : 7;

  printf("x: %d\n", x);
  printf("b: %d\n", b);
  printf("n: %d\n", n);

  return 0;

}
