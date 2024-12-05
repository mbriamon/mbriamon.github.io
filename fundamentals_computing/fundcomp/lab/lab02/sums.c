#include <stdio.h>
#include <math.h>

int main(){

  printf("Enter an integer: ");
  int x;
  scanf("%d", &x);

  int total1 = 0;
  double total2 = 0;

  for (int i = 1; i <= x; i++){
    total1 = total1 + (i * i);
    total2 = total2 + sqrt(i);
  }

  printf("The total of the squares is: %d\n", total1);
  printf("The total of the square roots is: %lf\n", total2);

  return 0;

}

