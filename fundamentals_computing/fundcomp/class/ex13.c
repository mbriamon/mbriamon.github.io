#include <stdio.h>

int main(){

/*
  //pre-loop test
  while (condition) {
    ...
    ...
  }

  //post-loop test
  do {
    ... 
    ...
  }
  while (condition);

  
  for(...){
    ...           IF PUT STATEMENT HERE, NEED TO INCLUDE CURLY BRACES, BECAUSE NO LONGER ONE CODE BLOCK
    for(...){
      ...
      ...
      ...
      ...
    }
  }         THESE CURLY BRACES ARE NOT NECESSARY BECAUSE THE LINES IN BETWEEN ARE ONE BLOCK(ONE FOR LOOP)

*/

  int n;
  int a,b;
  
  printf("enter a number: ");
  scanf("%d", &n);

  if(n == 1){
    a = 3;
    b = 4;
  }
  else if (n == 2){
    a = 5;
    b = 2;
  }
  else if(n == 3){
    a = 15;
    b = 21;
  }
    else{
    a = 0;
    b = 10;
  }

  return 0;

}
