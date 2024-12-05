#include <stdio.h>
#include <string.h>

#define MAXLENGTH 20
#define STATESMAX 50

int main(){
  
  char states[STATESMAX][MAXLENGTH];

  FILE * fp = fopen("usastates", "r");

  char astate[MAXLENGTH];

  int count = 0;
  while(1){
    fgets(astate, MAXLENGTH,  fp);
    if(feof(fp)) break;
    astate[strlen(astate)-1] = '\0';
    strcpy(states[count], astate);
    count++;
  }

  for(int i = 0; i < size; i++){
    for(int j = 0; j < strlen(states[i]); j++){
      printf("%c ", states[i][j]);
    }
    printf("\n");
  }

  return 0;
}
