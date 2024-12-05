#include <stdio.h>

int main(){
	
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	if(n >=0){
	  printf("number is positive \n");
	  printf("hello\n");
	}
	else{
	  printf("number is negative \n");
	  printf("whatever\n");
	}

	if (n > 4)
	  printf("hi\n");
	else{
	  printf("bye\n");
	  printf("see you later!\n");
	}

	return 0;
}


/*
 * logical operators: 
 >
 >=
 <
 <=
 ==
 !=
 

! not
&& and
|| or


*/
