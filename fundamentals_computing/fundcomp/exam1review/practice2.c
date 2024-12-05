#include <stdio.h>

int main(){

  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    printf("*");
  }
  printf("\n");

  for(int i = 1; i < n-1; i++){
    printf("*");
    for(int j = 1; j < n-1; j++){
      printf(" ");
    }
    printf("*\n");
  }

  for(int i = 0; i < n; i++){
    printf("*");
  }
  printf("\n");

  return 0;
}
