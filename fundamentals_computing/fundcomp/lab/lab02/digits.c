#include <stdio.h>

int main(){
  
  printf("Enter a positive integer: ");
  int x;
  scanf("%d", &x);

  int num;

  while(x > 0){
    num = x%10;
    printf("%d\n", num);
    x = x / 10;
  }

  return 0;

}
