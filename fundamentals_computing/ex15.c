#include <stdio.h>

void greetings();
void display(int);

int main(){
  
  greetings();

  int num = 34;
  display(num);

  return 0;

}

void greetings(void){
  printf("hi everyone!\n");
}

void display(a){
  printf("the value is: %d\n", a);
}
