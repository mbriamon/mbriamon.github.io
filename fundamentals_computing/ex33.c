#include <stdio.h>
#include <string.h>

#define MAX 20

int main(){

  char states[][MAX] = {"Indiana", "Michigan", "Ohio", "New York", "Mississippi"};
  
  int size = sizeof(states) / (MAX * sizeof(char));

  printf("%c\n", states[1][5]);
  printf("%s\n", states[3]);
  printf("%d\n", size);

  for(int i = 0; i < size; i++){
    printf("%s\n", states[i]);
  }

  for(int i = 0; i < size; i++){
    for(int j = 0; j < strlen(states[i]); j++){
      printf("%c ", states[i][j];
    }
    printf("\n");
  }

  return 0;
}
  	
