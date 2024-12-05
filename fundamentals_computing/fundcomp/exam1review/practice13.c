#include <stdio.h>

void histogram( int a[], int);

int main(){
  int arr[] = {4, 6, 2, 9, 5, 1, 6, 7};
  int size = sizeof(arr) / sizeof(int);

  histogram(arr, size);

  return 0;
}

void histogram(int a[], int sz){
  int value;
  for(int i = 0; i < sz; i++){
    value = a[i];
    for(int j = 0; j < value; j++){
      printf("%c", '*');
    }
    printf("\n");
  }
}
