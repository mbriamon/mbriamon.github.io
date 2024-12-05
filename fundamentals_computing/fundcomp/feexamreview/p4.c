#include <stdio.h>
#include <math.h>

double taylor1(double);
double taylor2(double);

int main(){
  double x = 0.75;
  double t1 = taylor1(x);
  double t2 = taylor2(x);
  printf("1: %lf\n", t1);
  printf("2: %lf\n", t2);

  return 0;
}
double taylor1(double x){
  double sum = 1;
  int power = 1;
  while(pow(x,power) > 0.001){
    sum = sum + pow(x, power);
    power++;
  }
  return sum;
}
double taylor2(double x){
  double val = 0, term = 1;
  int n = 0;

  while(term > 0.001){
    val = val + term;
    n++;
    term = pow(x,n);
  }
  return val;
}
