#include <stdio.h>

int main(){
  
  int num, dg;

  printf("Enter a number: ");
  scanf("%d", num);
  printf("Enter a digit: ");
  scanf("%d", dg);

  while (num > 0){
    if(num % 10 == dg){
      printf("True");
      break;
    }
    
  }
  return false;

