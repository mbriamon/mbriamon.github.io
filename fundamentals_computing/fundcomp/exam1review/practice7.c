#include <stdio.h>

int main(){

  int a[] = {4,9,2,8,4,3,8,7,6};
  int size = sizeof(a)/sizeof(a[0]);

  int temp = a[0];
  for(int i = 0; i < size-1; i++){
    a[i] = a[i+1];
  }
  a[size-1] = temp;

  for(int i = 0; i <size; i++){
    printf("%d ", a[i]);
  }

  return 0;

}
