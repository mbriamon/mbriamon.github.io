//plot for sine curve

#include <stdio.h>
#include <math.h>

int main(){

  //function: 10 * (2 + sin(x))
  
  printf("Plot for y = 10 * (2 + sin(x)) for x from 0 to 25\n");
  printf("  X     Y \n");
  
  double max = 0;
  double min = 0;
  double positionmax;
  double positionmin;

  double y = 0;

  for(double x = 0; x <= 25; x = x + 0.20){
    double a = sin(x);
    float b = 2 + a;
    y = 10 * b;
    
    if( y > max ){
      max = y;
      positionmax = x;
    }
    
    if( y <= min){
      min = y;
      positionmin = x;
    }

    printf(" %0.2lf  %0.2lf   ", x, y);

    int c = round(y);

    if(x < 9.80){
      printf(" ");
    }

    for(int i = 1; i <= c; i++){
      printf("#");
    }
    printf("\n");
  }

  printf("The maximum of %0.2lf was at %0.2lf \n", max, positionmax);
  printf("The minimum of %0.2lf was at %0.2lf \n", min, positionmin);
  printf("\n");
 
  return 0;

}
