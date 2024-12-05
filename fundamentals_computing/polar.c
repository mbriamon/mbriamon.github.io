//Mary Briamonte, Fund Comp Lab 3 Problem Part 2: Quardrants and Polar Coordinates
//The purpose of this assignment is to write a program that prompts the user for the x and y coordinates for a point, and then finds the quadrant, radius, and angle of that point. 

#include <stdio.h>
#include <math.h>

//function prototypes
int get_quadrant(double x, double y);
double get_radius(double x, double y);
double get_angle(double x, double y);
void show_info(int, double x, double y);


int main(){

  double x, y;

  printf("Enter X and Y coordinates: ");
  scanf("%lf %lf", &x, &y);

  int quad = get_quadrant(x,y);
  double radius = get_radius(x,y);
  double angle = get_angle(x,y);

  show_info(quad, radius, angle);
 
  return 0;

}
//functions
int get_quadrant(double x, double y){
  if(x >= 0){
    if(y >= 0){
      return 1;
    }
    else{
      return 4;
    }
  }
  else{
    if(y >= 0){
      return 2;
    }
    else{
      return 3;
    }
  }
}

double get_radius(double x, double y){
  double add = pow(x,2) + pow(y,2);
  double radius = pow(add, .5);
  return radius;
}

double get_angle(double x, double y){
  double divide = y / x;
  double angle = atan(divide);
  double degrees = angle * 180 / M_PI;
  return degrees;
}

void show_info(int a, double b, double c){
//  int quad = a;
//  double radius = b;
//  double angle = c;
  printf("The coordinate is in quadrant %d. This point has a radius of %lf, and an angle of %lf.\n", a,b,c);
}
