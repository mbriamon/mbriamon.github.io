#include "pathfunc.h"

int main(){

  Point a;
  Point pointList[MAX];

  char name[20];
  printf("please enter a file name: ");
  scanf("%s", name);

  int count = readValues(name, pointList);

  displayPoints(pointList, count);
  printf("\n");

  double distance = find_distance(pointList, count);
  printf("The path distance is: %.2lf\n", distance);

  return 0;

}

