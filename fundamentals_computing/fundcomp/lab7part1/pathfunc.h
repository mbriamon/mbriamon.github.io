#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 30

typedef struct{
  float x;
  float y;
} Point;

int readValues(char[], Point[]);
void displayPoints(Point[], int);
double find_distance(Point[], double);


