// testing the array shift function
#include <stdio.h>


int main()
{
  int arr[] = {4, 9, 2, 8, 4, 3, 8, 7, 6};
  int size = sizeof(arr)/sizeof(int);


  printf("original array order: ");
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("after 1st left shift: ");
  int arr2[size];
  for(int i = 0; i < size; i++){
    arr2[i] = 0;
  }
  for(int i = 1; i < size; i++){
    arr2[i-1] = arr[i];
  }
  for(int i = 0; i < size; i++){
    printf("%d ", arr2[i]);
  }

  printf("\n");

  printf("after circle shift: ");
  int arr3[size];
  for(int i = 1; i < size; i++){
    arr3[i-1] = arr2[i];
  }
  arr3[size-1] = arr2[0];
  for(int i = 0; i < size; i++){
    printf("%d ", arr3[i]);
  }
  printf("\n");

  return 0;
}

