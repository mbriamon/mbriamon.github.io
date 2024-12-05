// quad.c
// computes the roots of a quadratic equation

#include <stdio.h>
#include <math.h>

int main()
{
  double a, b, c, disc;
  double x1, x2;

  printf("Enter the coefficients (a,b,c) of a quadratic equation: ");
  scanf("%lf %lf %lf", &a, &b, &c);

  // ... rest of program goes here
  double p = 4 * a * c;
  double q = b * b;
  double discriminant = q - p;
  
  double y = sqrt(discriminant);
  
  double sol1 = ((-1 * b) + y)/(2*a);
  double sol2 = ((-1 * b) - y)/(2*a);

  if(discriminant > 0){
      printf("There are two solutions: %lf and %lf", sol1, sol2);
  }
  else if(discriminant = 0){
    printf("There is only one solution: %lf", sol1);
  }
  else{
    printf("There are no real solutions.");
  }
   

  return 0;
}

