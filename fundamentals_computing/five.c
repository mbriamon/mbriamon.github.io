#include <stdio.h>

int main(){

  int a[5];
  int num;

  printf("Enter 5 integers: \n");
  scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);

  for( int i = 4; i>=0; i--){
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;

}
