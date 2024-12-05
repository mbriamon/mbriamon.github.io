#include <stdio.h>

int main(){

  int a[20];
  int num;

  int count = 0;
  int i = 0;

  printf("Enter a few positive integers, ended with a -1:");

  while(1){

    scanf("%d", &num);

    if(num != -1){
      a[count] = num;
      count++;
    }
    else{
      break;
    }
  }

  for(int i = count-1; i >= 0; i--){
    printf("%d ", a[i]);
  }

  printf("\n");

  return 0;

}
