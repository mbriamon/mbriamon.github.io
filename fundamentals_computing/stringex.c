// stringex.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convert(char []);

int main()
{
  char line[80];

  printf("enter a line: ");
  fgets(line, 80, stdin);
  line[strlen(line)-1] = '\0';

  convert(line);

  printf("%s\n", line);

  return 0;
}

void convert(char string[]){
  char c;
  int i;

  for(int i = 0; i < strlen(string); i++){
    if(isspace(string[i])){
      string[i] = '_';
    }
    if(isupper(string[i])){
      string[i] = tolower(string[i]);
    }
  }


}

