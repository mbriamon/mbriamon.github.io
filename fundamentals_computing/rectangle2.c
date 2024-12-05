#include <stdio.h>

float find_perim(float len, float wid);
float find_area(float len, float wid);
int display(float perim, float area);

int main(){

 float len, wid;
 float perim, area;

 printf("enter the rectangle's length and width: ");
 scanf("%f %f", &len, &wid);


 perim = find_perim(len, wid);
 area = find_area(len, wid);

 display(perim, area);

 return 0;

}

float find_perim(float len, float wid){
  float perimeter = (2 * wid) + (2 * len);
  return perimeter;
}

float find_area(float len, float wid){
  float area = len * wid;
  return area;
}

int display(float perim, float area){
  printf("area = %0.2f   perimeter = %0.2f \n ", area, perim);
  return 0;
}
