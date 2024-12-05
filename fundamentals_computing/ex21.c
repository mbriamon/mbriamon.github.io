#include <stdio.h>
#include <stdio.h>

int main(){

  int n;

  n = 1;
  while(n <= 5){
    printf("%d  ", n);
    n++;
    printf("hello");
  }
  printf("\n");

  n = 1;
  while(true){
    printf("%d  ", n);
    if(n == 5) break;
    n++;
  }
  printf("\n");

  n = 1;
  bool isdone = false;
  while(!isdone){
    printf("%d  ", n);
    if (n == 5) isdone = true;
    n++;
  }
  printf("\n");

  return 0;

}
