//Mary Briamonte Fund Comp Lab 4: Part 1
//A Simple Array: Sets up an array with a number of grade values assigned at declaration time. The program then computes and displays the grades' average and their standard deviation. 

#include <stdio.h>
#include <math.h>

//function prototypes
float getAverage(float arr[], float length);
float getStdDev(float arr[], float length);

int main(){

  float grades[] = 
    { 96,73,62,87,80,63,93,79,71,99,
      82,83,80,97,89,82,93,92,95,89,
      71,97,91,95,63,81,76,98,64,86,
      74,79,98,82,77,68,87,70,75,97,
      71,94,68,87,79 };

  float size = sizeof(grades) / sizeof(grades[0]);

  float avg = getAverage(grades, size);
  float sd = getStdDev(grades, size);

  printf("Average: %0.2f\n", avg);
  printf("Standard Deviation: %0.2f\n", sd);

  return 0;

}


//function definitions
float getAverage(float arr[], float length){
  float sum = 0;
  for( int i = 0; i < length; i++){
    sum = sum + arr[i];
  }
  float avg = sum / length;
  return avg;
}
float getStdDev(float arr[], float length){
  float mean = getAverage(arr, length);
  float diffSquared = 0;
  for( int i = 0; i <length; i++){
    diffSquared += (arr[i] - mean) * (arr[i] - mean);
  }
  float variance = diffSquared / length;
  float stddev = sqrt(variance);
  return stddev;
}

