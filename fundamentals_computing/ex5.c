#include <stdio.h>

int max( int a, int b);  //function prototype

int main(){

  int a, b, m;

  a = 5;
  b = 8;

  m = max(a,b);

  printf("max is %d\n", m);
  
  int x = 33, y = 22, z;
  z = max(x,y);
  printf("other maz is %d\n", z);

  return 0;

}

int max(int a, int b){
  return (a > b) ? a : b;
}
