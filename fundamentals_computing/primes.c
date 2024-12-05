//Mary Briamonte Fund Comp Lab 4: Part 2
//Prime Numbers: finds all the prime numbers between 1 and 1,000


#include <stdio.h>

int main(){

  int array[1000];

  for( int i = 0; i < 1001; i++){
    array[i] = 1;
  }
  
  for(int i = 2; i <1001; i++){
    for(int j = i+1; j <1001; j++){
      if( (j % i) == 0){
        array[j] = 0;
      }
    }
  }
  
  int count = 0;
  for(int index = 2; index < 1001; index++){
    if(array[index] == 1){
      printf("%3d ", index);
      count++;
      if(count == 10){
        printf("\n");
	count = 0;
      }
    }
  }
  printf("\n");


  return 0;

}
