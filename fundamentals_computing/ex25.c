#include <stdio.h>

int main(){

  int a[5];  //a is an array of 5 int's

  printf("%d\n", sizeof(a));

  a[0] = 34;
  a[1] = 13;
  a[2] = 8;
  a[3] = 63;
  a[4] = 63;

  for (int i = 0; i < 5; i++){
    printf("%d ", a[i]);
  }
  printf("\n");


  int b[10] = {33, 24, 53, 76, 48, 9, 33, 25, 41, 21};

  for(int i = 0; i < 10; i++){
    printf("%d\n", b[i]);
  }

  return 0;
}
