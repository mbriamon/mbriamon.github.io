#include <stdio.h>

int main(){
	
	int n = 1;
	
	//condition-controlled loop
	while(n <= 10){
	  printf("n: %d\n", n);
	  n++;
	  if(n == 5) continue;
	  printf("hi\n");
	  
	}

	printf("\n");

	printf("n is now: %d\n",n);
	

	//counter-controlled loop
	for (int i = 1; i <= 10; i++){
	  printf("%d ",i);
	}

	printf("\n");
	printf("i is now: %d\n", i);

	return 0;
}


/* 1. initialization
 * 2. repetition condition
 * 3. update
