#include <stdio.h>

int arraysum(int [], int);

#define size 6

int main(){
  int arr[size] = {23, 25, 14, 37, 31, 41};

  int sum = arraysum(arr, size);

  printf("sum is %d\n", sum);

  return 0;

}

int arraysum(int a[], int size){
  int s = 0;
  for(int i = 0; i <size; i++){
    s = s + a[i];
  }

  return s;
}
