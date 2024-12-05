#include <stdio.h>

int main(){

  char str[] = "notre dame";

  puts(str);

  fputs(str, stdout);
  printf("\n");

  return 0;
}
