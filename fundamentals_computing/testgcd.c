#include <stdio.h>

int get_gcd(int a, int b);

int main(){

int x, y;

 printf("enter 2 integers: ");
 scanf("%d %d", &x, &y);

 int value = get_gcd(x, y);

 printf("the greatest common denominator is: %d.\n", value);

 return 0;

}

int get_gcd(int a, int b){
  int gcd = 0;
  for(int i = 1; i <= a && i <= b; i++){
    if(a % i == 0 && b % i ==0){
      gcd = i;
    }
  }
  return gcd;
}
