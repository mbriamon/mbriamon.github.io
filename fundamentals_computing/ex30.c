#include <stdio.h>

int main(){

  char str[20] = "notre dame";

  printf("%d\n", sizeof(str));
  printf("%d\n", strlen(str));
  printf("%d\n", sizeof("notre dame"));

  char x;
  x = 'A';
  printf("%d\n", sizeof(x));
  printf("%d\n", sizeof('A'));
  printf("%d\n", sizeof("A"));

  printf("%s\n", str);




  return 0;

}
