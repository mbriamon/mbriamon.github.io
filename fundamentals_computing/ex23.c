#include <stdio.h>
#include <stdbool.h>

void menu();

int main() {

  int n;
  bool isdone = false

  printf("enter 1 or 2 or 3: ");
  scanf("%d", &n);

  while(! isdone){
    
    switch(n) {
      case 1:
        printf("you entered option 1\n");
        break;
      case 2:
        printf("you entered option 2\n");
        break;
      case 3: 
        printf("you entered option 3\n");
        break;
      case 4:
        isdone = true;
	printf("you chose to quit\n");
	break;
      default:
        printf("incorrect choice\n");
    }
  }
  
  printf("goodbye!\n");

  return 0;

}


void menu(){
  int n;
 
  printf("1: option 1\n");
  printf("2: option 2\n");
  printf("3: option 3\n");
  printf("4: quit\n");

  printf("enter your choice: ");
  scanf("%d", &n);
}
