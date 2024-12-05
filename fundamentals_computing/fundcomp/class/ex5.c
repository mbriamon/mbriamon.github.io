#include <stdio.h>

int main(){
	int a,b;
	a=3;

	b=5+a++;

	printf("a: %d  b: %d\n", a, b);
	
	a=3;
	b=5+ ++a;
	printf("a: %d   b: %d\n", a,b);

	return 0;
}
