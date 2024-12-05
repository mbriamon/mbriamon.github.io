#include <stdio.h>

int main(){

  int sum = 0;

  for(int i = 1; i <= 3; i++){
    for(int j = 1; j <= 2; j++){
      sum = sum + i*j;

    }
  }

  printf("sum: %d\n", sum);

  return 0;

}


//
//
  if(condition) {
    ...
    ...
  }
  else {
    ...
    ...
  }
