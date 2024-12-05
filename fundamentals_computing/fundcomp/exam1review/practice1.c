#include <stdio.h>

int main(){

  int n;
  printf("Enter n (2-9): ");
  scanf("%d", &n);

  int num_arr[n];
  int value = 1;
  for(int i = 0; i < n; i++){
    num_arr[i] = value;
    for(int j = 0; j <= i; j++){
      printf("%d ", num_arr[j]);
    }
    printf("\n");
    value = value + 1;
  }
  
  for(int i = n-2; i >= 0; i--){
    for(int j = 0; j <= i; j++){
      printf("%d ", num_arr[j]);
    }
    printf("\n");
  }

  return 0;
}
