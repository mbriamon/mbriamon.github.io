//program to make multiplication table based on the size requirements entered by user

#include <stdio.h>

int main() {

//determining the size of table
  int x, y;
  
  printf("Enter the x size of the table: ");
  scanf("%d", &x);
  printf("Enter the y size of the table: ");
  scanf("%d", &y);

//create table
  printf("*  \t");
  for(int j = 1; j <= x; j++){
    printf("%d \t", j);
  }

  printf("\n");

  printf("  ---");
  for(int j = 1; j <= x; j++){
    printf("--------");
  }
  
  printf("\n");

  int num;

  for(int i = 1; i <= y; i++){
    printf("%d |\t", i);
    for(int j = 1; j <= x; j++){
      num = i * j;
      printf("%2.d\t", num);
    }
    printf("\n");
  }

  return 0;

}
