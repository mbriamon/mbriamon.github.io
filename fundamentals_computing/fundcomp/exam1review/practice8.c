#include <stdio.h>

int main(){
  int arr[];
  arr = {3,7,8,2};

  int x = sizeof(arr)/sizeof(int);

  printf("%d\n", x);

  return 0;
}
