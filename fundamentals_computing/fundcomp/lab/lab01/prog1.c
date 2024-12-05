//prog1.c
//C program to compute score of a football team

#include <stdio.h>

int main(){
	//declare the variables
	int touchdowns;
	int extra_points;
	int field_goals;
	int safeties;

	//get inputs from the user
	printf("Enter the number of touchdowns scored by the Irish: ");
	scanf("%d", &touchdowns);

	printf("Enter the number of extra points made by the Irish: ");
	scanf("%d", &extra_points);

	printf("Enter the number of field goals made by the Irish: ");
	scanf("%d", &field_goals);

	printf("Enter the number of safeties scored by the Irish: ");
	scanf("%d", &safeties);

	//calculate points
	int td_points, fg_points, s_points;
	td_points = touchdowns * 6;
	fg_points = field_goals * 3;
	s_points = safeties * 2;

	//calculate the total
	int total;
	total = td_points + extra_points + fg_points + s_points;

	//display the total
	printf("The total number of points scored by the Irish is: %d\n", total);

	return 0;
}

