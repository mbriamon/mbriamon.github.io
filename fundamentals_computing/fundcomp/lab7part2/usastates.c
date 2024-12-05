//Mary Briamonte    usastates.c

#include "statesfunc.h"

int main(){

  const int statesMax = 100;
  State States[statesMax];

  char name[MAXNAME];
  printf("please enter a file name: ");
  scanf("%s", name);

  int count = readValues(name, States);

  displayMenu(count, States);

  return 0;
}

