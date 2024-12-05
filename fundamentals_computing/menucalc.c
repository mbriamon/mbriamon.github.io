//Mary Briamonte, Fund Comp Lab 3 Problem Part 3: Text Menu Calculator
//The purpose of this program is to act as a text menu-driven basic calculator for the add, subtract, multiply, and divide. 

#include <stdio.h>

//function prototypes
int menu();
double get_numbers();
double get_add(double a, double b);
double get_subtract(double a, double b);
double get_multiply(double a, double b);
double get_divide(double a, double b);


int main(){

  int choice;
  choice = menu();
 
  double num1, num2;
 
  double answer;

//loop so program continutes until user decides to exit
  while(choice != 6){
    if(choice == 1){
      num1 = get_numbers();
      num2 = get_numbers();
      answer = get_add(num1, num2);
      printf("The answer is: %lf\n", answer);
    }
    else if(choice == 2){
      num1 = get_numbers();
      num2 = get_numbers();
      answer = get_subtract(num1, num2);
      printf("The answer is: %lf\n", answer);
    }
    else if(choice == 3){
      num1 = get_numbers();
      num2 = get_numbers();
      answer = get_multiply(num1, num2);
      printf("The answer is: %lf\n", answer);
    }
    else if(choice == 4){
      num1 = get_numbers();
      num2 = get_numbers();
      answer = get_divide(num1, num2);
      printf("The answer is: %lf\n", answer);
    }
    else{
      printf("Good bye!\n");
      break;
    }
   
    printf("\n");
    choice = menu();
 
  }

  return 0;

}

//functions
int menu(){
  int choice;
  
  printf("What would you like to do?\n");
  
  printf("1 for addition\n");
  printf("2 for subtraction\n");
  printf("3 for multiplication\n");
  printf("4 for division\n");
  printf("5 to exit\n");

  printf("enter your choice: ");
  scanf("%d", &choice);

  return choice;
}

double get_numbers(){
  double num;
  printf("Enter a number: \n");
  scanf("%lf", &num);

  return num;
}

double get_add(double a, double b){
  return a + b;
}

double get_subtract(double a, double b){
  return a - b;
}

double get_multiply(double a, double b){
  return a * b;
}

double get_divide(double a, double b){
  return a / b;
}
