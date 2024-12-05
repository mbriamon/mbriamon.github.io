//prog2.c
//C program that computes the result of a formula 

#include <stdio.h>

int main(){
	//declare the variables
	int width;
	int height;
	int length;

	//get inputs from the user
	printf("Enter the width of the box: ");
	scanf("%d", &width);

	printf("Enter the height of the box: ");
	scanf("%d", &height);

	printf("Enter the length of the box: ");
	scanf("%d", &length);

	//calculate volume
	int volume;
	volume = width * height * length;

	//display the total
	printf("The volume of the box is: %d\n", volume);

	return 0;
}
