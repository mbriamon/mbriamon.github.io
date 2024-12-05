#include <stdio.h>

int main(){

  int n;
  int a, b;

  printf("enter a number: ");
  scanf("%d", &n);

  switch(n) {
    case 1:
      a = 3;
      b = 4;
      break;
    case 2:
      a = 5;
      b = 2;
      break;
    case 3:
      a = 15;
      b = 21;
      break;
    default:
      a = 0;
      b = 10;
  }

  printf("a: %d   b: %d\n", a, b);

  return 0;

}
