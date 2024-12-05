#include <stdio.h>

int main(){

  int a, b, sum;
  
  FILE * fp = fopen("nums.txt", "r");
  fscanf(fp, "%d %d", &a, &b);
  sum = a + b;
  printf("the sume of %d and %d is %d\n", a, b, sum);

  FILE * ofp = fopen("sumoutput.txt", "w");
  fprintf(ofp, "the sume of %d is %d\n", a, b, sum);

  fclose(fp);
  fclose(ofp);

  return 0;
}
