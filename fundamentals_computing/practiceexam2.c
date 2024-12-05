// ex74.c
//  a pointer to a struct
#include <stdio.h>
#include <stdbool.h>
void incommon_p(char *, char *);

int main()
{

  char word1[] = "irish";
  char word2[] = "stay";

  incommon_p(word1, word2);
  /*
  if(result == true){
    printf("true\n");
  }
  else{
    printf("false\n");
  }
*/

  return 0;
}

void incommon_p(char *word1, char *word2){

  int result = 0;
  //char letter1 = ' ';
  //char letter2 = ' ';
  char *l1 = word1;
  char *l2 = word2;
  while( *l1 != '\0'){
    //letter1 = l1;
    printf("%c ", l1);
    while( *l2 != '\0'){
      //letter2 = l2;
      printf("%c \n", l2);
      if(l1 == l2){
        printf("true");
	result++;
      }
      l2++;
    }
    l1++;
  }
  if(result == 0){
    printf("false");
  }
}

