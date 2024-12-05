#include <stdio.h>

double myfunc(double);

int main(){
  double x;
  double y;
  printf("Enter x: ");
  scanf("%lf", &x);

  printf("%lf\n", x);
/*
  y = myfunc(x);
  printf("sum: %lf", y);
*/


  double sum1 = x + 1;
  double value = x;
  int check = 1;
  while(check == 1){
    value = value * x;
    if(value > 0.001){
      sum1 = sum1 + value;
    }
    else{
      check = 0;
    }
  }
  printf("sum: %lf", sum1);

}

double myfunc(double x){
  double sum = 1 + x;
  int check = 1;
  while(check == 1){
    double value = x;
    value = value * x;
    if(value > 0.001){
      sum = sum + value;
    }
    else{
      check = 0;
    }
  }
  return sum;
}
