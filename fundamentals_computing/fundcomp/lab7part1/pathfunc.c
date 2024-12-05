#include "pathfunc.h"

//function to read values of points from the value and edit point list
int readValues(char name[], Point pointList[]){
  
  FILE *fp = fopen(name, "r");
  if(!fp){
    printf("file %s is not found", name);
    exit(1);
  }
    
  int count = 0;
  while(1){
    fscanf(fp, "%f %f", &pointList[count].x, &pointList[count].y);
    if(feof(fp))break;
    count++;
  }
  return count;
}

//function to display the points in a chart
void displayPoints(Point pointList[], int count){
  printf("There are %d points:\n", count);
  printf("  x   |   y\n");
  printf("------+------\n");
  for(int i = 0; i < count; i++){
    printf("%5.2f | %5.2f\n", pointList[i].x, pointList[i].y);
  }

}

//function to find the path distance between all the points
double find_distance(Point list[], double count){

  Point point1, point2;

  double distance = 0;
  double distanceX, distanceY, distanceTemp;
  for(int i = 1; i < count; i++){
    point1 = list[i-1];
    point2 = list[i];
    
    distanceX = point1.x - point2.x;
    distanceX = pow(distanceX, 2);
    distanceY = point1.y - point2.y;
    distanceY = pow(distanceY, 2);

    distanceTemp = sqrt(distanceX + distanceY);

    distance = distance + distanceTemp;

  }

  return distance;
}

