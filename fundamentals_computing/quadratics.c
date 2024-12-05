//Mary Briamonte
//Fund Comp
//Lab 3 Part 1
//multiple quadratics: expand on a program from lab 2's in class exercise 1. keeps reading sets of 3 numbers and calculating the roots until the user enters 0 for a, this will terminate the program

#include <stdio.h>
#include <math.h>

//function prototype
float get_discriminant(int a, int b, int c);

int main(){

//initializng 3 variables, and reading in a set of 3 numbers from the user
  int a, b, c;
  printf("Enter 3 integers: ");
  scanf("%d %d %d", &a, &b, &c);

//loop used, so that when the a value is entered as 0, the function will terminate
  while( a != 0){

    float dis = get_discriminant(a, b,c);
    
    double sq = sqrt(dis);

//calculating the roots
    double sol1 = ((-1 * b) + sq) / (2 * a);
    double sol2 = ((-1 * b) - sq) / (2 * a);

//if conditions to determine the number of solutions the numbers have
    if(dis > 0) {
      printf("There are 2 solutions: %f and %f\n", sol1, sol2);
    }
    else if(dis = 0){
      printf("There is only one solution: %f\n", sol1);
    }
    else{
      printf("There are no real solutions.\n");
    }

    printf("Enter 3 integers: ");
    scanf("%d %d %d", &a, &b, &c);
  }

  return 0;

}

//get_discriminant calculates the discriminant of the function, when called it will help determine how many solutions the set of 3 numbers has
float get_discriminant(int a, int b, int c){
  float x = 4 * a * c;
  float y = b * b;
  float discriminant = y - x;

  return discriminant;
}
