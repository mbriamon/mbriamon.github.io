#include <stdio.h>

int main() {

  int n, a;

  printf("enter n: ");
  scanf("%d", &n);

    a = 7;
    a = 3;

//ternary operator    ?:    operator
  a = (n > 0) ? 3 : 7;

  int x,y,z, max;

  printf("enter three numbers: ");
  scanf("%d %d %d", &x, &y, &z);

  max = (x >= y) && (x >= z) ? x : ((y >= z) && (y >= x) ? y : z);

  int max2 = (x > y) ? ((x > z) ? x :z ) : (y >z) ? y : z;

  printf("max: %d\n", max);
  printf("max2: %d\n", max2);



  return 0;
 
}
