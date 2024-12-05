#include <stdio.h>

int main(){

  int num[] = {7,5,9,2,6,4};
  int size = sizeof(num)/sizeof(num[0]);

  int end_index = size -1;
  for(int i = 0; i < size/2; i++){
    int temp = num[i];
    num[i] = num[end_index];
    num[end_index] = temp;
    end_index--;
  }
  for(int i = 0; i < size; i++){
    printf("%d ", num[i]);
  }

  return 0;

}
