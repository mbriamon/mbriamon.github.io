#include <stdio.h>

int main(){

  int a, b;
  bool done = false;   //flag

  for(a = 101; a <= 105 && !done; a++){
    printf("%d: ", a);
   
   for(b = 1; b <= 10; b++){
      printf("%d ", b);
      if( (a == 103) && (b == 7) ) break;
    }
   
   printf("\n");
  }


  return 0;

}
